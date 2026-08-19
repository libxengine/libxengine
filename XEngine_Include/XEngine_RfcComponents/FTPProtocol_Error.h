#pragma once
/********************************************************************
//    Created:     2026/08/06  14:30:00
//    File Name:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_FTPProtocol\FTPProtocol_Error.h
//    File Path:   D:\xengine\XEngine_SourceCode\XEngine_RfcComponents\RfcComponents_FTPProtocol
//    File Base:   FTPProtocol_Error
//    File Ext:    h
//    Project:     XEngine
//    Author:      qyt
//    Purpose:     FTP导出错误
//    History:
*********************************************************************/
/************************************************************************/
/*                     FTP协议解析错误                                  */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_PARAMENT 0x71E0000        //参数错误
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_MALLOC 0x71E0001          //内存分配失败
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_NOTFOUND 0x71E0002        //未找到客户端
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_NOPACKET 0x71E0003        //没有包了
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_BUFFERSIZE 0x71E0004      //缓冲区大小不够
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_DATA 0x71E0005            //数据错误
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_EMPTY 0x71E0006           //数据为空
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PARSE_NOTCOMPLETE 0x71E0007     //数据不完整
/************************************************************************/
/*                     FTP协议打包错误                                  */
/************************************************************************/
#define ERROR_RFCCOMPONENTS_FTP_PROTOCOL_PACKET_PARAMENT 0x71E1000         //参数错误