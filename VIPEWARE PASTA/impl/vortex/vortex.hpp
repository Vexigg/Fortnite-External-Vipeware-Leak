#ifndef VORTEX_HPP
#define VORTEX_HPP
#define DEVICE "\\\\.\\{03b97230-7e66-4cdd-ad13-de42e2dde530}"

struct IO_STATUS_BLOCK1 {
	union {
		NTSTATUS Status;
		PVOID Pointer;
	};
	ULONG_PTR Information;
};

using PIO_STATUS_BLOCK1 = IO_STATUS_BLOCK1*;
using PIO_APC_ROUTINE1 = void(NTAPI*)(
	PVOID,
	PIO_STATUS_BLOCK1,
	std::uint32_t);

extern "C" __int64 direct_device_control(
	HANDLE FileHandle,
	HANDLE Event,
	PIO_APC_ROUTINE1 ApcRoutine,
	PVOID ApcContext,
	PIO_STATUS_BLOCK1 IoStatusBlock,
	std::uint32_t IoControlCode,
	PVOID InputBuffer,
	std::uint32_t InputBufferLength,
	PVOID OutputBuffer,
	std::uint32_t OutputBufferLength);

namespace vortex
{
	class communicate_t
	{
		typedef enum _requests
		{
			invoke_start,
			invoke_base,
			invoke_region,
			invoke_read,
			invoke_write,
			invoke_pattern,
			invoke_success,
			invoke_unique,
			invoke_mouse,

		}requests, * prequests;

		typedef struct _read_invoke {
			uint32_t pid;
			uintptr_t address;
			void* buffer;
			size_t size;
		} read_invoke, * pread_invoke;

		typedef struct _write_invoke {
			uint32_t pid;
			uintptr_t address;
			void* buffer;
			size_t size;
		} write_invoke, * pwrite_invoke;

		typedef struct _base_invoke {
			uint32_t pid;
			uintptr_t handle;
			const char* name;
			size_t size;
		} base_invoke, * pbase_invoke;

		typedef struct _region_invoke {
			uintptr_t address;
		} region_invoke, * pregion_invoke;

		typedef struct _invoke_data
		{
			uint32_t unique;
			requests code;
			void* data;
		}invoke_data, * pinvoke_data;

		std::int32_t m_pid = 0;
		HANDLE m_handle = 0;

	public:

		std::uintptr_t image_base = 0;

		[[nodiscard]] bool send_cmd(void* data, requests code);
		[[nodiscard]] bool initialize_handle();
		[[nodiscard]] bool attach(int a_pid);
		[[nodiscard]] const std::uintptr_t get_image_base(const char* module_name);
		[[nodiscard]] std::uintptr_t get_guarded_pool();
		[[nodiscard]] bool is_guarded(std::uintptr_t Address);
		[[nodiscard]] std::uintptr_t fix_address(std::uintptr_t Address);

		[[nodiscard]] bool read_physical(const uintptr_t address, void* buffer, const size_t size);
		[[nodiscard]] bool write_physical(const uintptr_t address, void* buffer, const size_t size);

		template <typename t>
		[[nodiscard]] auto write(const uintptr_t address, t value) -> bool
		{
			return this->write_physical(address, &value, sizeof(t));
		}

		template <typename t>
		[[nodiscard]] auto read(const uintptr_t address) -> t
		{
			t response{};
			this->read_physical(address, &response, sizeof(t));
			return response;
		}

		template <typename t>
		[[nodiscard]] auto read_array(const uintptr_t address, t buffer, size_t size) -> bool
		{
			return this->read_physical(address, buffer, size);
		}
	};
}
// can create a global instance, or call it
static vortex::communicate_t* ctx = new vortex::communicate_t();

#endif // include 