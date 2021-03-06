#pragma once
#include "stdafx.h"

#define TAG_AAC_SEQUENCE_HEADER 0x00
#define TAG_AAC_RAW_DATA        0x01

class  CAudioData
{
public:
	CAudioData(void* buf = NULL);
	~CAudioData(void);
	/*送入数据*/
	void OnData(void* buf);

	/*获取音频数据*/
	uchar_t* GetPdata() const;
	
	/*获取 ACC_packet_type*/
	uchar_t GetACC_packet_type() const;
	/*打印信息*/
	void print_info() const ;

protected:

private:
	/*Audio 信息*/
	uchar_t  m_sound_type	:1;			//类型 0--sndMono   1--sndStereo
	uchar_t  m_sound_size	:1;			//精度 0--8bits     1--16bits
	uchar_t  m_rate			:2;			//采样率 0--5.5kHz  1--11KHz 2--22kHz  3--44kHz
	uchar_t  m_sound_format	:4;			//音频编码类型 10 -- AAC

	
	/*audio  数据区*/
	uchar_t  m_ACC_packet_type;			//0--AAC sequence header        1--AAC raw  data   

	uchar_t* m_pdata;

};

