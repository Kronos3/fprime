// ======================================================================
// \title Os/Models/Models.cpp
// \brief test used to validate Os/Models before use
// ======================================================================
#include "Os/Models/FileStatusEnumAc.hpp"
#include "Os/Models/FileModeEnumAc.hpp"
#include "Os/Models/TaskStatusEnumAc.hpp"
#include "Os/Models/MutexStatusEnumAc.hpp"
#include "Os/Models/DirectoryStatusEnumAc.hpp"
#include "Os/Models/DirectoryOpenModeEnumAc.hpp"
#include "Os/Models/RawTimeStatusEnumAc.hpp"
#include "Os/Models/FileSystemStatusEnumAc.hpp"
#include "Os/Models/GenericStatusEnumAc.hpp"
#include "Os/Models/QueueStatusEnumAc.hpp"
#include "Os/Models/QueueBlockingTypeEnumAc.hpp"
#include "Os/File.hpp"
#include "Os/Task.hpp"
#include "Os/Mutex.hpp"
#include "Os/Directory.hpp"
#include "Os/FileSystem.hpp"
#include "Os/Os.hpp"
#include "Os/RawTime.hpp"
#include "Os/Queue.hpp"

// Check consistency of every constant in the Os::File::Status enum
static_assert(static_cast<FwIndexType>(Os::File::Status::MAX_STATUS) ==
              static_cast<FwIndexType>(Os::FileStatus::NUM_CONSTANTS),
              "File status and FPP shadow enum have inconsistent number of values");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::OP_OK) == Os::FileStatus::T::OP_OK,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::DOESNT_EXIST) == Os::FileStatus::T::DOESNT_EXIST,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::NO_SPACE) == Os::FileStatus::T::NO_SPACE,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::NO_PERMISSION) == Os::FileStatus::T::NO_PERMISSION,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::BAD_SIZE) == Os::FileStatus::T::BAD_SIZE,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::NOT_OPENED) == Os::FileStatus::T::NOT_OPENED,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::FILE_EXISTS) == Os::FileStatus::T::FILE_EXISTS,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::NOT_SUPPORTED) == Os::FileStatus::T::NOT_SUPPORTED,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::INVALID_MODE) == Os::FileStatus::T::INVALID_MODE,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::INVALID_ARGUMENT) == Os::FileStatus::T::INVALID_ARGUMENT,
              "File status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileStatus::T>(Os::File::Status::OTHER_ERROR) == Os::FileStatus::T::OTHER_ERROR,
              "File status and FPP shadow enum do not match");

// Check consistency of every constant in the Os::File::Mode enum
static_assert(static_cast<FwIndexType>(Os::File::Mode::MAX_OPEN_MODE) ==
              static_cast<FwIndexType>(Os::FileMode::NUM_CONSTANTS),
              "File mode and FPP shadow enum have inconsistent number of values");
static_assert(static_cast<Os::FileMode::T>(Os::File::Mode::OPEN_NO_MODE) == Os::FileMode::T::OPEN_NO_MODE,
              "File mode and FPP shadow enum do not match");
static_assert(static_cast<Os::FileMode::T>(Os::File::Mode::OPEN_READ) == Os::FileMode::T::OPEN_READ,
              "File mode and FPP shadow enum do not match");
static_assert(static_cast<Os::FileMode::T>(Os::File::Mode::OPEN_CREATE) == Os::FileMode::T::OPEN_CREATE,
              "File mode and FPP shadow enum do not match");
static_assert(static_cast<Os::FileMode::T>(Os::File::Mode::OPEN_WRITE) == Os::FileMode::T::OPEN_WRITE,
              "File mode and FPP shadow enum do not match");
static_assert(static_cast<Os::FileMode::T>(Os::File::Mode::OPEN_SYNC_WRITE) == Os::FileMode::T::OPEN_SYNC_WRITE,
              "File mode and FPP shadow enum do not match");
static_assert(static_cast<Os::FileMode::T>(Os::File::Mode::OPEN_APPEND) == Os::FileMode::T::OPEN_APPEND,
              "File mode and FPP shadow enum do not Mode");

static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::OP_OK) == Os::TaskStatus::T::OP_OK,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::INVALID_HANDLE) == Os::TaskStatus::T::INVALID_HANDLE,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::INVALID_PARAMS) == Os::TaskStatus::T::INVALID_PARAMS,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::INVALID_STACK) == Os::TaskStatus::T::INVALID_STACK,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::UNKNOWN_ERROR) == Os::TaskStatus::T::UNKNOWN_ERROR,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::INVALID_AFFINITY) == Os::TaskStatus::T::INVALID_AFFINITY,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::DELAY_ERROR) == Os::TaskStatus::T::DELAY_ERROR,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::JOIN_ERROR) == Os::TaskStatus::T::JOIN_ERROR,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::ERROR_RESOURCES) == Os::TaskStatus::T::ERROR_RESOURCES,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::ERROR_PERMISSION) == Os::TaskStatus::T::ERROR_PERMISSION,
              "Task status and FPP shadow enum do not match");
static_assert(static_cast<Os::TaskStatus::T>(Os::Task::Status::INVALID_STATE) == Os::TaskStatus::T::INVALID_STATE,
              "Task status and FPP shadow enum do not match");

static_assert(static_cast<Os::MutexStatus::T>(Os::Mutex::Status::OP_OK) == Os::MutexStatus::T::OP_OK,
              "Mutex status and FPP shadow enum do not match");
static_assert(static_cast<Os::MutexStatus::T>(Os::Mutex::Status::ERROR_BUSY) == Os::MutexStatus::T::ERROR_BUSY,
              "Mutex status and FPP shadow enum do not match");
static_assert(static_cast<Os::MutexStatus::T>(Os::Mutex::Status::ERROR_DEADLOCK) == Os::MutexStatus::T::ERROR_DEADLOCK,
              "Mutex status and FPP shadow enum do not match");
static_assert(static_cast<Os::MutexStatus::T>(Os::Mutex::Status::ERROR_OTHER) == Os::MutexStatus::T::ERROR_OTHER,
              "Mutex status and FPP shadow enum do not match");


// Check consistency of every constant in the Os::Directory::Status enum
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::OP_OK) == Os::DirectoryStatus::T::OP_OK,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::DOESNT_EXIST) == Os::DirectoryStatus::T::DOESNT_EXIST,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::NO_PERMISSION) == Os::DirectoryStatus::T::NO_PERMISSION,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::NOT_OPENED) == Os::DirectoryStatus::T::NOT_OPENED,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::NOT_DIR) == Os::DirectoryStatus::T::NOT_DIR,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::NO_MORE_FILES) == Os::DirectoryStatus::T::NO_MORE_FILES,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::FILE_LIMIT) == Os::DirectoryStatus::T::FILE_LIMIT,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::BAD_DESCRIPTOR) == Os::DirectoryStatus::T::BAD_DESCRIPTOR,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::ALREADY_EXISTS) == Os::DirectoryStatus::T::ALREADY_EXISTS,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::NOT_SUPPORTED) == Os::DirectoryStatus::T::NOT_SUPPORTED,
              "Directory status and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryStatus::T>(Os::Directory::Status::OTHER_ERROR) == Os::DirectoryStatus::T::OTHER_ERROR,
              "Directory status and FPP shadow enum do not match");


// Check consistency of every constant in the Os::Directory::Mode enum
static_assert(static_cast<FwIndexType>(Os::Directory::OpenMode::MAX_OPEN_MODE) ==
              static_cast<FwIndexType>(Os::DirectoryOpenMode::NUM_CONSTANTS),
              "File mode and FPP shadow enum have inconsistent number of values");
static_assert(static_cast<Os::DirectoryOpenMode::T>(Os::Directory::OpenMode::READ) == Os::DirectoryOpenMode::T::READ,
              "Directory mode and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryOpenMode::T>(Os::Directory::OpenMode::CREATE_IF_MISSING) == Os::DirectoryOpenMode::T::CREATE_IF_MISSING,
              "Directory mode and FPP shadow enum do not match");
static_assert(static_cast<Os::DirectoryOpenMode::T>(Os::Directory::OpenMode::CREATE_EXCLUSIVE) == Os::DirectoryOpenMode::T::CREATE_EXCLUSIVE,
              "Directory mode and FPP shadow enum do not match");


// Check consistency of every constant in the Os::FileSystem::Status enum
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::OP_OK) == Os::FileSystemStatus::T::OP_OK,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::ALREADY_EXISTS) == Os::FileSystemStatus::T::ALREADY_EXISTS,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::NO_SPACE) == Os::FileSystemStatus::T::NO_SPACE,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::NO_PERMISSION) == Os::FileSystemStatus::T::NO_PERMISSION,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::NOT_DIR) == Os::FileSystemStatus::T::NOT_DIR,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::IS_DIR) == Os::FileSystemStatus::T::IS_DIR,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::NOT_EMPTY) == Os::FileSystemStatus::T::NOT_EMPTY,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::INVALID_PATH) == Os::FileSystemStatus::T::INVALID_PATH,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::DOESNT_EXIST) == Os::FileSystemStatus::T::DOESNT_EXIST,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::FILE_LIMIT) == Os::FileSystemStatus::T::FILE_LIMIT,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::BUSY) == Os::FileSystemStatus::T::BUSY,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::NO_MORE_FILES) == Os::FileSystemStatus::T::NO_MORE_FILES,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::BUFFER_TOO_SMALL) == Os::FileSystemStatus::T::BUFFER_TOO_SMALL,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::EXDEV_ERROR) == Os::FileSystemStatus::T::EXDEV_ERROR,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::OVERFLOW_ERROR) == Os::FileSystemStatus::T::OVERFLOW_ERROR,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::NOT_SUPPORTED) == Os::FileSystemStatus::T::NOT_SUPPORTED,
              "FileSystem status and FPP shadow enum do not match");
static_assert(static_cast<Os::FileSystemStatus::T>(Os::FileSystem::Status::OTHER_ERROR) == Os::FileSystemStatus::T::OTHER_ERROR,
              "FileSystem status and FPP shadow enum do not match");


// Check consistency of every constant in the Os::RawTime::Status enum
static_assert(static_cast<Os::RawTimeStatus::T>(Os::RawTime::Status::OP_OK) == Os::RawTimeStatus::T::OP_OK,
              "RawTime status enums do not match");
static_assert(static_cast<Os::RawTimeStatus::T>(Os::RawTime::Status::OP_OVERFLOW) == Os::RawTimeStatus::T::OP_OVERFLOW,
              "RawTime status enums do not match");
static_assert(static_cast<Os::RawTimeStatus::T>(Os::RawTime::Status::INVALID_PARAMS) == Os::RawTimeStatus::T::INVALID_PARAMS,
              "RawTime status enums do not match");
static_assert(static_cast<Os::RawTimeStatus::T>(Os::RawTime::Status::OTHER_ERROR) == Os::RawTimeStatus::T::OTHER_ERROR,
              "Generic status enums do not match");

// Check consistency of every constant in the Os::Queue::Status enum
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::OP_OK) == Os::QueueStatus::T::OP_OK,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::ALREADY_CREATED) == Os::QueueStatus::T::ALREADY_CREATED,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::EMPTY) == Os::QueueStatus::T::EMPTY,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::UNINITIALIZED) == Os::QueueStatus::T::UNINITIALIZED,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::SIZE_MISMATCH) == Os::QueueStatus::T::SIZE_MISMATCH,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::SEND_ERROR) == Os::QueueStatus::T::SEND_ERROR,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::RECEIVE_ERROR) == Os::QueueStatus::T::RECEIVE_ERROR,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::INVALID_PRIORITY) == Os::QueueStatus::T::INVALID_PRIORITY,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::FULL) == Os::QueueStatus::T::FULL,
              "Queue status enums do not match");
static_assert(static_cast<Os::QueueStatus::T>(Os::Queue::Status::UNKNOWN_ERROR) == Os::QueueStatus::T::UNKNOWN_ERROR,
              "Queue status enums do not match");

// Check consistency of every constant in the Os::Queue::BlockingType enum
static_assert(static_cast<Os::QueueBlockingType::T>(Os::Queue::BlockingType::BLOCKING) == Os::QueueBlockingType::T::BLOCKING,
              "Queue BlockingType enums do not match");
static_assert(static_cast<Os::QueueBlockingType::T>(Os::Queue::BlockingType::NONBLOCKING) == Os::QueueBlockingType::T::NONBLOCKING,
              "Queue BlockingType enums do not match");

// Check Generic mappings
static_assert(static_cast<Os::GenericStatus::T>(Os::Generic::Status::OP_OK) == Os::GenericStatus::T::OP_OK,
              "Generic status enums do not match");
static_assert(static_cast<Os::GenericStatus::T>(Os::Generic::Status::ERROR) == Os::GenericStatus::T::ERROR,
              "Generic status enums do not match");
