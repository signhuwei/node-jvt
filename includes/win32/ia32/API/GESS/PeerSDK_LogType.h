#pragma once

/**
* @brief Specifies type of system log.
*/
enum LogType
{
    /**
    * Indicates a power on event.
    */
    LogType_PowerOn = 0,

    /**
    * Indicates a channel recording event.
    */
    LogType_RecordCH = 1,

    /**
    * Indicates a videoloss event.
    */
    LogType_VLoss = 2,

    /**
    * Indicates a sensor triggerred event.
    */
    LogType_Sensor = 3,

    /**
    * Indicates a video motion event.
    */
    LogType_Motion = 4,

    /**
    * Indicates a user login event.
    */
    LogType_Login = 5,

    /**
    * Indicates a user logout event.
    */
    LogType_Logout = 6,

    /**
    * Indicates a event that user exports or downloads system configuration.
    */
    LogType_ConfigExport = 7,

    /**
    * Indicates a event that user restores system configuration.
    */
    LogType_ConfigDefault = 8,

    /**
    * Indicates a event that user imports another system configuration.
    */
    LogType_ConfigImport = 9,

    /**
    * Indicates a event that user exports system log.
    */
    LogType_LogExport = 10,

    /**
    * Indicates a event that user erases all system logs.
    */
    LogType_LogClear = 11,

    /**
    * Indicates a event that user changes system (peer) time.
    */
    LogType_ChangeDateTime = 12,

    /**
    * Indicates a event that user changes recording configuration.
    */
    LogType_ChangeRecordSetting = 13,

    /**
    * Indicates a event that user formats HDDs.
    */
    LogType_HDDFormat = 14,

    /**
    * Indicates a event that user changes HDD flags.
    */
    LogType_HDDSet = 15,

    /**
    * Indicates a event that user upgrade firmware.
    */
    LogType_Upgrade = 16,

    /**
    * Indicates a event that user perform a backup job.
    */
    LogType_Backup = 17,

    /**
    * Indicates a event that administrator password has changed.
    */
    LogType_ChangeAdminPass = 18,

    /**
    * Indicates no HDD in system event.
    */
    LogType_NoHDD = 19,

    /**
    * Indicates all HDDs are full.
    */
    LogType_HDDFull = 20,

    /**
    * Indicates a HDD error event.
    */
    LogType_HDDError = 21,

    /**
    * Indicates a MCU error event.
    */
    LogType_MCUError = 22,

    /**
    * Indicates a system error event.
    */
    LogType_SystemError = 23,

    /**
    * Indicates a event that system failed to write HDD.
    */
    LogType_WriteError = 24,

    /**
    * Indicates a event that system reboots.
    */
    LogType_Reboot = 25,
};
