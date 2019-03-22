//
//  "$Id$"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __COMM_KEYMAP_H__
#define __COMM_KEYMAP_H__

#include "Types/Types.h"
#include "Types/Keyboard.h"

// 数字键映射
#define KEY_0            (uchar)('0')
#define KEY_1            (uchar)('1')
#define KEY_2            (uchar)('2')
#define KEY_3            (uchar)('3')
#define KEY_4            (uchar)('4')
#define KEY_5            (uchar)('5')
#define KEY_6            (uchar)('6')
#define KEY_7            (uchar)('7')
#define KEY_8            (uchar)('8')
#define KEY_9            (uchar)('9')
#define KEY_10           (uchar)('Q')
#define KEY_11           (uchar)('W')
#define KEY_12           (uchar)('E')
#define KEY_13           (uchar)('R')
#define KEY_14           (uchar)('T')
#define KEY_15           (uchar)('Y')
#define KEY_16           (uchar)('U')
#define KEY_17           (uchar)('I')
#define KEY_18           (uchar)('O')
#define KEY_19           (uchar)('P')
#define KEY_20           (uchar)('G')
#define KEY_21           (uchar)('H')
#define KEY_22           (uchar)('J')
#define KEY_23           (uchar)('K')
#define KEY_24           (uchar)('L')
#define KEY_25           (uchar)('B')
#define KEY_26           (uchar)('N')
#define KEY_27           (uchar)('M')
#define KEY_28           VK_OEM_FJ_JISHO
#define KEY_29           VK_OEM_FJ_MASSHOU
#define KEY_30           VK_OEM_FJ_TOUROKU
#define KEY_31           VK_OEM_FJ_LOYA
#define KEY_32           VK_OEM_FJ_ROYA

#define KEY_10PLUS       VK_OEM_3    // '~`'

// 控制键映射
#define KEY_UP            VK_UP
#define KEY_DOWN          VK_DOWN
#define KEY_LEFT          VK_LEFT
#define KEY_RIGHT         VK_RIGHT
#define KEY_SHIFT         VK_ALT
#define KEY_PGUP          VK_PRIOR
#define KEY_PGDN          VK_NEXT
#define KEY_RET           VK_RETURN
#define KEY_ESC           VK_ESCAPE
#define KEY_FUNC          VK_CONTROL

// 快捷键映射
#define KEY_REC           VK_F1
#define KEY_SEARCH        VK_F2
#define KEY_INFO          VK_F3
#define KEY_ALARM         VK_F4
#define KEY_ADDR          VK_F5
#define KEY_BACKUP        VK_F6
#define KEY_SPLIT         VK_F7
#define KEY_SPLIT1        VK_F8
#define KEY_SPLIT4        VK_F9
#define KEY_SPLIT8        VK_F10
#define KEY_SPLIT9        VK_F11
#define KEY_SPLIT16       VK_F12
#define KEY_SPLIT25       VK_F13
#define KEY_SPLIT36       VK_F14
#define KEY_SPLIT5_8      VK_F15
#define KEY_SPLIT9_12     VK_F16
#define KEY_SPLIT13_16    VK_F17
#define KEY_SPLIT17_20    VK_F18
#define KEY_SPLIT21_24    VK_F19
#define KEY_SPLIT25_28    VK_F20
#define KEY_SPLIT29_32    VK_F21
#define KEY_SPLIT9_16     VK_F22
#define KEY_SPLIT17_24    VK_F23
#define KEY_SPLIT25_32    VK_F24
#define KEY_SPLIT8_16     VK_ATTN
#define KEY_SPLIT17_25    VK_CRSEL
#define KEY_SPLIT24_32    VK_EXSEL
#define KEY_SPLIT17_32    VK_EREOF
#define KEY_SHUT          VK_SLEEP
#define KEY_MENU		(uchar)('A')
#define KEY_HDD			(uchar)('S')
#define KEY_SPEAK		(uchar)('D')
#define KEY_SNAP		(uchar)('F')
#define KEY_REBOOT		(uchar)('Z')
#define KEY_ALARMRESET	(uchar)('X')	//报警复位，报警信息清除按键
#define KEY_OPEN_ALL_REC    (uchar)('C')
#define KEY_CLOSE_ALL_REC   (uchar)('V')
#define KEY_LOGOUT        VK_LOGOUT        //注销键
#define KEY_HOME          VK_HOME          //返回监控画面
#define KEY_DELETE		VK_DELETE	//删除键	

// 回放键映射
#define KEY_PLAY          VK_MEDIA_PLAY_PAUSE
#define KEY_BACK          VK_BACK
#define KEY_STOP          VK_MEDIA_STOP     // ''"' for US
#define KEY_FAST          VK_OEM_PLUS  // '+' any country
#define KEY_SLOW          VK_OEM_MINUS // '-' any country
#define KEY_NEXT          VK_MEDIA_NEXT_TRACK
#define KEY_PREV          VK_MEDIA_PREV_TRACK
#define KEY_NEXTFRAME         VK_OEM_6    //  ']}' for US
#define KEY_PREVFRAME         VK_OEM_4    //  '[{' for US
#define KEY_STEPX         VK_OEM_5    //  '\|' for US
#define KEY_TOUR         VK_OEM_1    //  '\|' for US
#define KEY_FASTBACK     VK_FASTBACK //快退

// 云台控制键映射
#define KEY_PTZ           VK_NUMPAD8   // '8' 云台控制菜单
#define KEY_TELE          VK_NUMPAD7   // '7' 望远
#define KEY_WIDE          VK_NUMPAD9   // '9' 广角
#define KEY_IRIS_CLOSE    VK_NUMPAD1   // '1' 光圈小
#define KEY_IRIS_OPEN     VK_NUMPAD3   // '3' 光圈大
#define KEY_FOCUS_NEAR    VK_NUMPAD4   // '4' 焦距拉近
#define KEY_FOCUS_FAR     VK_NUMPAD6   // '6' 焦距拉远
#define KEY_BRUSH         VK_NUMPAD5   // '5' 雨刷
#define KEY_LIGHT         VK_NUMPAD2   // '2' 灯光
#define KEY_SPRESET       VK_ADD       // '+' 设置预置点
#define KEY_GPRESET       VK_MULTIPLY  // '*' 转到预置点
#define KEY_DPRESET       VK_SUBTRACT  // '-' 删除预置点
#define KEY_PATTERN       VK_NUMPAD0   // 云台模式
#define KEY_SCANON        VK_DECIMAL   // '.' 点间巡航
#define KEY_SCANOFF		  VK_OEM_2
#define KEY_AUTOPANON       VK_DIVIDE    // '/' 线扫
#define KEY_AUTOPANOFF		VK_OEM_3
#define KEY_AUTOTOUR      VK_SCROLL     // scroll lock
#define KEY_PAUSE		  VK_PAUSE
#define KEY_MUTE		 VK_VOLUME_MUTE   //静音		  


// 读取默认键映射
#define KEY_RESET			VK_OEM_RESET // 恢复出厂设置
#define KEY_ZOOM			VK_ZOOM		// 缩放，位移量

#define KEY_NOUSE			VK_ALT		// 未定义键
#define KEY_SPACE			VK_SPACE	// 空格键
#define KEY_COMMA			VK_OEM_COMMA	// 逗号
#define KEY_PERIOD	 		VK_OEM_PERIOD	// 句号
#define KEY_DIGIT			VK_ICO_00		// 数字输入键 -/--

#define KEY_PREVCHAN		VK_LSHIFT
#define KEY_NEXTCHAN		VK_RSHIFT
#define KEY_MUTE			VK_VOLUME_MUTE //静音
#define KEY_VOLUME_UP       VK_VOLUME_UP   //音量+
#define KEY_VOLUME_DOWN     VK_VOLUME_DOWN //音量-

#define KEY_CD_OPEN         VK_INSERT      //刻录机光盘进出仓

#endif
