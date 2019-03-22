#pragma once

/**
* @brief Specifies flags of HDD.
*/
enum HDDFlag
{
    /**
    * Indicates no flag is set.
    */
    HDDFlag_None = 0,

    /**
    * Indicates a read-only HDD.
    */
    HDDFlag_ReadOnly = 1,

    /**
    * Indicates a writable HDD.
    */
    HDDFlag_Writable = 2,

    /**
    * Indicates a writable and overwritable HDD.
    */
    HDDFlag_Overwritable = 3,
};
