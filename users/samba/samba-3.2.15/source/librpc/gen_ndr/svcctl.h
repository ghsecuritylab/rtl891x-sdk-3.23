/* header auto-generated by pidl */

#include <stdint.h>

#ifndef _HEADER_svcctl
#define _HEADER_svcctl

#define SERVICE_TYPE_KERNEL_DRIVER	( 0x01 )
#define SERVICE_TYPE_FS_DRIVER	( 0x02 )
#define SERVICE_TYPE_ADAPTER	( 0x04 )
#define SERVICE_TYPE_RECOGNIZER_DRIVER	( 0x08 )
#define SERVICE_TYPE_DRIVER	( SERVICE_TYPE_KERNEL_DRIVER|SERVICE_TYPE_FS_DRIVER|SERVICE_TYPE_RECOGNIZER_DRIVER )
#define SERVICE_TYPE_WIN32_OWN_PROCESS	( 0x10 )
#define SERVICE_TYPE_WIN32_SHARE_PROCESS	( 0x20 )
#define SERVICE_TYPE_WIN32	( SERVICE_TYPE_WIN32_OWN_PROCESS|SERVICE_TYPE_WIN32_SHARE_PROCESS )
#define SERVICE_STATE_ACTIVE	( 0x01 )
#define SERVICE_STATE_INACTIVE	( 0x02 )
#define SERVICE_STATE_ALL	( 0x03 )
#define SV_TYPE_ALL	( 0xFFFFFFFF )
struct SERVICE_LOCK_STATUS {
	uint32_t is_locked;
	const char *lock_owner;/* [unique,charset(UTF16)] */
	uint32_t lock_duration;
};

struct SERVICE_STATUS {
	uint32_t type;
	uint32_t state;
	uint32_t controls_accepted;
	WERROR win32_exit_code;
	uint32_t service_exit_code;
	uint32_t check_point;
	uint32_t wait_hint;
};

struct ENUM_SERVICE_STATUS {
	const char * service_name;/* [relative,flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
	const char * display_name;/* [relative,flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
	struct SERVICE_STATUS status;
};

/* bitmap svcctl_ServerType */
#define SV_TYPE_WORKSTATION ( 0x00000001 )
#define SV_TYPE_SERVER ( 0x00000002 )
#define SV_TYPE_SQLSERVER ( 0x00000004 )
#define SV_TYPE_DOMAIN_CTRL ( 0x00000008 )
#define SV_TYPE_DOMAIN_BAKCTRL ( 0x00000010 )
#define SV_TYPE_TIME_SOURCE ( 0x00000020 )
#define SV_TYPE_AFP ( 0x00000040 )
#define SV_TYPE_NOVELL ( 0x00000080 )
#define SV_TYPE_DOMAIN_MEMBER ( 0x00000100 )
#define SV_TYPE_PRINTQ_SERVER ( 0x00000200 )
#define SV_TYPE_DIALIN_SERVER ( 0x00000400 )
#define SV_TYPE_SERVER_UNIX ( 0x00000800 )
#define SV_TYPE_NT ( 0x00001000 )
#define SV_TYPE_WFW ( 0x00002000 )
#define SV_TYPE_SERVER_MFPN ( 0x00004000 )
#define SV_TYPE_SERVER_NT ( 0x00008000 )
#define SV_TYPE_POTENTIAL_BROWSER ( 0x00010000 )
#define SV_TYPE_BACKUP_BROWSER ( 0x00020000 )
#define SV_TYPE_MASTER_BROWSER ( 0x00040000 )
#define SV_TYPE_DOMAIN_MASTER ( 0x00080000 )
#define SV_TYPE_SERVER_OSF ( 0x00100000 )
#define SV_TYPE_SERVER_VMS ( 0x00200000 )
#define SV_TYPE_WIN95_PLUS ( 0x00400000 )
#define SV_TYPE_DFS_SERVER ( 0x00800000 )
#define SV_TYPE_ALTERNATE_XPORT ( 0x20000000 )
#define SV_TYPE_LOCAL_LIST_ONLY ( 0x40000000 )
#define SV_TYPE_DOMAIN_ENUM ( 0x80000000 )

enum SERVICE_CONTROL
#ifndef USE_UINT_ENUMS
 {
	FIXME=1
}
#else
 { __donnot_use_enum_SERVICE_CONTROL=0x7FFFFFFF}
#define FIXME ( 1 )
#endif
;


struct svcctl_CloseServiceHandle {
	struct {
		struct policy_handle *handle;/* [ref] */
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_ControlService {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t control;
	} in;

	struct {
		struct SERVICE_STATUS *service_status;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_DeleteService {
	struct {
		struct policy_handle *handle;/* [ref] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_LockServiceDatabase {
	struct {
		struct policy_handle *handle;/* [ref] */
	} in;

	struct {
		struct policy_handle *lock;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_QueryServiceObjectSecurity {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t security_flags;
		uint32_t buffer_size;/* [range(0,0x40000)] */
	} in;

	struct {
		uint8_t *buffer;/* [ref,size_is(buffer_size)] */
		uint32_t *needed;/* [ref,range(0,0x40000)] */
		WERROR result;
	} out;

};


struct svcctl_SetServiceObjectSecurity {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t security_flags;
		uint8_t *buffer;/* [ref,size_is(buffer_size)] */
		uint32_t buffer_size;
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_QueryServiceStatus {
	struct {
		struct policy_handle *handle;/* [ref] */
	} in;

	struct {
		struct SERVICE_STATUS *service_status;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_SetServiceStatus {
	struct {
		WERROR result;
	} out;

};


struct svcctl_UnlockServiceDatabase {
	struct {
		struct policy_handle *lock;/* [ref] */
	} in;

	struct {
		struct policy_handle *lock;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_NotifyBootConfigStatus {
	struct {
		WERROR result;
	} out;

};


struct svcctl_SCSetServiceBitsW {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t bits;
		uint32_t bitson;
		uint32_t immediate;
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_ChangeServiceConfigW {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t type;
		uint32_t start;
		uint32_t error;
		const char *binary_path;/* [unique,charset(UTF16)] */
		const char *load_order_group;/* [unique,charset(UTF16)] */
		const char *dependencies;/* [unique,charset(UTF16)] */
		const char *service_start_name;/* [unique,charset(UTF16)] */
		const char *password;/* [unique,charset(UTF16)] */
		const char *display_name;/* [unique,charset(UTF16)] */
	} in;

	struct {
		uint32_t *tag_id;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_CreateServiceW {
	struct {
		struct policy_handle *scmanager_handle;/* [ref] */
		const char *ServiceName;/* [charset(UTF16)] */
		const char *DisplayName;/* [unique,charset(UTF16)] */
		uint32_t desired_access;
		uint32_t type;
		uint32_t start_type;
		uint32_t error_control;
		const char *binary_path;/* [charset(UTF16)] */
		const char *LoadOrderGroupKey;/* [unique,charset(UTF16)] */
		uint8_t *dependencies;/* [unique,size_is(dependencies_size)] */
		uint32_t dependencies_size;
		const char *service_start_name;/* [unique,charset(UTF16)] */
		uint8_t *password;/* [unique,size_is(password_size)] */
		uint32_t password_size;
		uint32_t *TagId;/* [unique] */
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t *TagId;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_EnumDependentServicesW {
	struct {
		struct policy_handle *service;/* [ref] */
		uint32_t state;
		uint32_t buf_size;
	} in;

	struct {
		struct ENUM_SERVICE_STATUS *service_status;/* [unique] */
		uint32_t *bytes_needed;/* [ref] */
		uint32_t *services_returned;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_EnumServicesStatusW {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t type;
		uint32_t state;
		uint32_t buf_size;
		uint32_t *resume_handle;/* [unique] */
	} in;

	struct {
		uint8_t *service;/* [size_is(buf_size)] */
		uint32_t *bytes_needed;/* [ref] */
		uint32_t *services_returned;/* [ref] */
		uint32_t *resume_handle;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_OpenSCManagerW {
	struct {
		const char *MachineName;/* [unique,charset(UTF16)] */
		const char *DatabaseName;/* [unique,charset(UTF16)] */
		uint32_t access_mask;
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_OpenServiceW {
	struct {
		struct policy_handle *scmanager_handle;/* [ref] */
		const char *ServiceName;/* [charset(UTF16)] */
		uint32_t access_mask;
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_QueryServiceConfigW {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t buf_size;
	} in;

	struct {
		uint8_t *query;
		uint32_t *bytes_needed;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_QueryServiceLockStatusW {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t buf_size;
	} in;

	struct {
		struct SERVICE_LOCK_STATUS *lock_status;/* [ref] */
		uint32_t *required_buf_size;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_StartServiceW {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t NumArgs;
		const char *Arguments;/* [unique,charset(UTF16)] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_GetServiceDisplayNameW {
	struct {
		struct policy_handle *handle;/* [ref] */
		const char *service_name;/* [unique,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
	} in;

	struct {
		const char **display_name;/* [ref,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_GetServiceKeyNameW {
	struct {
		struct policy_handle *handle;/* [ref] */
		const char *service_name;/* [unique,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
	} in;

	struct {
		const char **key_name;/* [ref,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_SCSetServiceBitsA {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t bits;
		uint32_t bitson;
		uint32_t immediate;
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_ChangeServiceConfigA {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t type;
		uint32_t start;
		uint32_t error;
		const char *binary_path;/* [unique,charset(UTF16)] */
		const char *load_order_group;/* [unique,charset(UTF16)] */
		const char *dependencies;/* [unique,charset(UTF16)] */
		const char *service_start_name;/* [unique,charset(UTF16)] */
		const char *password;/* [unique,charset(UTF16)] */
		const char *display_name;/* [unique,charset(UTF16)] */
	} in;

	struct {
		uint32_t *tag_id;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_CreateServiceA {
	struct {
		struct policy_handle *handle;/* [ref] */
		const char *ServiceName;/* [unique,charset(UTF16)] */
		const char *DisplayName;/* [unique,charset(UTF16)] */
		uint32_t desired_access;
		uint32_t type;
		uint32_t start_type;
		uint32_t error_control;
		const char *binary_path;/* [unique,charset(UTF16)] */
		const char *LoadOrderGroupKey;/* [unique,charset(UTF16)] */
		const char *dependencies;/* [unique,charset(UTF16)] */
		const char *service_start_name;/* [unique,charset(UTF16)] */
		const char *password;/* [unique,charset(UTF16)] */
	} in;

	struct {
		uint32_t *TagId;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_EnumDependentServicesA {
	struct {
		struct policy_handle *service;/* [ref] */
		uint32_t state;
		uint32_t buf_size;
	} in;

	struct {
		struct ENUM_SERVICE_STATUS *service_status;/* [unique] */
		uint32_t *bytes_needed;/* [ref] */
		uint32_t *services_returned;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_EnumServicesStatusA {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t type;
		uint32_t state;
		uint32_t buf_size;
		uint32_t *resume_handle;/* [unique] */
	} in;

	struct {
		uint8_t *service;/* [size_is(buf_size)] */
		uint32_t *bytes_needed;/* [ref] */
		uint32_t *services_returned;/* [ref] */
		uint32_t *resume_handle;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_OpenSCManagerA {
	struct {
		const char *MachineName;/* [unique,charset(UTF16)] */
		const char *DatabaseName;/* [unique,charset(UTF16)] */
		uint32_t access_mask;
	} in;

	struct {
		struct policy_handle *handle;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_OpenServiceA {
	struct {
		struct policy_handle *scmanager_handle;/* [ref] */
		const char *ServiceName;/* [unique,charset(UTF16)] */
		uint32_t access_mask;
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_QueryServiceConfigA {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t buf_size;
	} in;

	struct {
		uint8_t *query;
		uint32_t *bytes_needed;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_QueryServiceLockStatusA {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t buf_size;
	} in;

	struct {
		struct SERVICE_LOCK_STATUS *lock_status;/* [ref] */
		uint32_t *required_buf_size;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_StartServiceA {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t NumArgs;
		const char *Arguments;/* [unique,charset(UTF16)] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_GetServiceDisplayNameA {
	struct {
		struct policy_handle *handle;/* [ref] */
		const char *service_name;/* [unique,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
	} in;

	struct {
		const char **display_name;/* [ref,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_GetServiceKeyNameA {
	struct {
		struct policy_handle *handle;/* [ref] */
		const char *service_name;/* [unique,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
	} in;

	struct {
		const char **key_name;/* [ref,charset(UTF16)] */
		uint32_t *display_name_length;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_GetCurrentGroupeStateW {
	struct {
		WERROR result;
	} out;

};


struct svcctl_EnumServiceGroupW {
	struct {
		WERROR result;
	} out;

};


struct svcctl_ChangeServiceConfig2A {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t info_level;
		uint8_t *info;/* [unique] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_ChangeServiceConfig2W {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t info_level;
		uint8_t *info;/* [unique] */
	} in;

	struct {
		WERROR result;
	} out;

};


struct svcctl_QueryServiceConfig2A {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t info_level;
		uint32_t buf_size;
	} in;

	struct {
		uint8_t *buffer;
		uint32_t *bytes_needed;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_QueryServiceConfig2W {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t info_level;
		uint32_t buf_size;
	} in;

	struct {
		uint8_t *buffer;
		uint32_t *bytes_needed;/* [ref] */
		WERROR result;
	} out;

};


struct svcctl_QueryServiceStatusEx {
	struct {
		struct policy_handle *handle;/* [ref] */
		uint32_t info_level;
		uint32_t buf_size;
	} in;

	struct {
		uint8_t *buffer;
		uint32_t *bytes_needed;/* [ref] */
		WERROR result;
	} out;

};


struct EnumServicesStatusExA {
	struct {
		struct policy_handle *scmanager;/* [ref] */
		uint32_t info_level;
		uint32_t type;
		uint32_t state;
		uint32_t buf_size;
		uint32_t *resume_handle;/* [unique] */
	} in;

	struct {
		uint8_t *services;
		uint32_t *bytes_needed;/* [ref] */
		uint32_t *service_returned;/* [ref] */
		const char **group_name;/* [ref,charset(UTF16)] */
		uint32_t *resume_handle;/* [unique] */
		WERROR result;
	} out;

};


struct EnumServicesStatusExW {
	struct {
		struct policy_handle *scmanager;/* [ref] */
		uint32_t info_level;
		uint32_t type;
		uint32_t state;
		uint32_t buf_size;
		uint32_t *resume_handle;/* [unique] */
	} in;

	struct {
		uint8_t *services;
		uint32_t *bytes_needed;/* [ref] */
		uint32_t *service_returned;/* [ref] */
		const char **group_name;/* [ref,charset(UTF16)] */
		uint32_t *resume_handle;/* [unique] */
		WERROR result;
	} out;

};


struct svcctl_SCSendTSMessage {
	struct {
		WERROR result;
	} out;

};

#endif /* _HEADER_svcctl */