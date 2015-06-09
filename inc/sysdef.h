#ifndef SYSDEF_H
#define SYSDEF_H

//////////////////////////////////////////////////////////////////////////
#define SYSDEF_VER				(0x000001)

//////////////////////////////////////////////////////////////////////////
#define MAX_COLORS				12
#define MAX_GROUPS              4
#define MAX_CHANELS             384
#define MAX_EXTEND_FILE			99
#define MAX_HEADS_PER_COLOR		8

//ÿ����ͷ���Ķµ�����������������ϴ��ͷ�������ͷ
#define MAX_JAMMED_DOT_COUNT	100
#define NORMAL_DOT				1000
#define JAMMED_DOT				1020
//////////////////////////////////////////////////////////////////////////

//Macro define
#define ALIGNUP(X, Y) (((X) + (Y) - 1)/(Y)*(Y))
#define	ALIGN(X, Y)	((X)/(Y)*(Y))	//X��Y����
#define MM_TO_DOT(X,DPI)  (int)((double)(X*DPI)/25.4)   
#define DOT_TO_MM(X,DPI)  (int)(((double)X*25.4)/DPI)
#define LIMIT(NUM, MINLIMIT, MAXLIMIT) (((NUM)<(MAXLIMIT))?(((NUM)>(MINLIMIT))?(NUM):(MINLIMIT)):(MAXLIMIT))
//////////////////////////////////////////////////////////////////////////

//ϵͳ�쳣����
typedef enum _IMAGEPROCESS_EXCEPTION
{
	PE_SUCCESS = 0,
	PE_PROCESS_IMG_FAILED,		// ͼ�����쳣
	PE_OPEN_PRINTFILE_FAILED,	// ���ļ�ʧ��
	PE_CREATE_DATABUFFER_FAILED,// �������ݻ�����ʧ��
	PE_OUT_OF_PRINT_RANGE,		// ��ǰ���񳬳���ӡ��Χ
	PE_WAIT_EVENT_OVERTIME,		// �̵߳ȴ���ʱ	
	PE_WRITE_MEMORY_FAILED,		// д�ڴ�ʧ��
	PE_DOWNLOADTHREAD_TERMINATE_FAILED,// д�ڴ��߳��ж�
	PE_COLOR_OFFSET_OUTOF_RANGE,	// ƫ��ֵԽ��
	PE_LOADIMGDATATHREAD_TERMINATE_FAILED,// ��ȡͼ�������߳��ж�
	PE_UNKOWN_RIP_FILE_TYPE,	// ������RIP�ļ�����
	PE_HASP_EXPIRED				// ���ܹ�����
}IMAGEPROCESS_EXCEPTION, LIMAGEPROCESS_EXCEPTION;

// ������ɫ
enum MACH_COLORTYPE{
	MC_4C = 0,
	MC_4C_W,
	MC_4C_W_V,
	MC_4C_2W,
	MC_6C,
	MC_6C_W,
	MC_6C_W_V,
	MC_6C_2W,
	MC_6C_V,
	MC_6C_2V,
	MC_8C,
	MC_12C
};

enum MACH_HEADERTYPE{
	HT_SP512 = 0, 
	HT_SG1024,
	HT_XAAR_1001,
	HT_KM512,
	HT_KM1024
};

// ͬɫ��ͷ�����з�ʽ
enum MACH_GROUPTYPE{
	MG_VERTICAL = 0,   // ��������
	MG_HORIZONTAL	   // ��������
};

enum BANK_TYPE{
	A_BANK,
	B_BANK,
	BANK_ALL
};

enum WHITE_PRINT_POS{
	WP_TOP = 0,
	WP_BOTTOM,
	WP_MIDDLE
};//��ɫ��ӡλ��

enum PRINT_DIR{
	DIR_LEFT = 0,
	DIR_RIGHT,
	DIR_MAX
};//X���ӡ����

enum PRT_IMG_TYPE{
	NORMAL_IMG,						// ����ͼ
	HEAD_STATE_IMAGE,				// ״̬ͼ
	HEAD_MODIFY_IMAGE,				// ����ͼ
	HEAD_INSIDECOLUMN_IMAGE,		// �ڲ�����ɫͼ
	HEAD_GROUPOFFSET_IMAGE,			// ����ɫͼ
	HEAD_BIDIRECTIONAL_IMAGE,		// ������ӡ��ɫͼ
	HEAD_CROSSCOLOR_BASECOLOR_IMAGE,// ��ͷ��ɫͼ
	HEAD_SETP_IMAGE					// ��������ͼ
};//��ӡͼ������

enum DIR{
	DIR_X = 0,
	DIR_Y,
	MAX_DIRS
};//��ӡ����

enum SUPERBLOCK_TYPE{
	SUPERBLOCK_FILEDPI = 0,
	SUPERBLOCK_PRINTDPI
}; // �����������

enum COLOR{
	COLOR_K = 0,
	COLOR_C,
	COLOR_M,
	COLOR_Y,
	COLOR_LC,
	COLOR_LM,
	COLOR_W,
	COLOR_V,
	COLOR_ALL
};

enum PASS_MODE{
	TEST = 0,  // 1
	DRAFT,					// 2
	NORMAL,					// 4
	NORMAL_PLUS,			// 6
	ENHANCE,				// 8
	ULTRA,					// 16
	ULTRA_DRAFT,			// 32
	ULTRA_NORMAL,			// 64
	THREEPASS,				// 3
	FIVEPASS,				// 5
	SEVENPASS,              // 7
	NINEPASS,				// 9
	TENPASS,				// 10
	ULTRA_12,               // 12
	ULTRA_13,               // 13
	ULTRA_14,				// 14
	EIGHTTEENPASS,			// 18
	ULTRA_17,				// 17
	ULTRA_34,				// 34
	ULTRA_33,				// 33
	ULTRA_15,
	ULTRA_20,				// 20
	ULTRA_21,
	ULTRA_24,				// 24
	ULTRA_26,               // 26
	ULTRA_27,
	ULTRA_28,				// 28
	ULTRA_30,
	ULTRA_36,				// 36
	ULTRA_39,
	ULTRA_42,
	ULTRA_51,
	ULTRA_54,
	ULTRA_66,				// 66
	ULTRA_68,				// 68
	ULTRA_99,
	ULTRA_102,
	MAX_PASS_MODES
};//��ӡPassģʽ

enum PRINT_MODE{
	MODE_NORMAL = 0,
	MODE_MULTI,
	MODE_REGION
	//MODE_SINGLECOLOR,        // ��ɫ��ӡ
	//SEQUENCE_PRINT,          // ������ӡ
	//STEP_PRINT               // ������ӡ
};

enum NOIZE_UNIT_TYPE{
	ONE_TO_ZERO_TWO = 0,
	TWO_TO_ONE_THREE,
	THREE_TO_TWO_FOUR,
	FOUR_TO_THREE,
	MAX_NOIZE_UNIT
};

enum NOIZE_UNIT_RANDOM_TYPE{
	MINUS_RANDOM = 0,
	ADD_RANDOM,
	NOIZE_UNIT_MAX_RANDOM
};
//////////////////////////////////////////////////////////////////////////

//RIP file Informations
typedef struct __RIPFILEHEADINFO
{
	long Signature;
	long XDPI;
	long YDPI;
	long BytesPerLine;	//ÿ�е��ֽ���
	long Height;		//����
	long Width;			//ÿ�е�������
	long PaperWidth;
	long Colors;		//��ɫ����rip�ļ�ʵ�ʸ߶�=Height��colors
	long Reserved[4];
}RIPFILEHEADINFO, *LPRIPFILEHEADINFO;

//REGIN_INFO ����λ��mm��
typedef struct __REGIN_INFO
{
	float	Left;
	float	Top;
	float	Width;
	float	Length;
}REGIN_INFO, *LPREGIN_INFO;

//RANDOM_INFO����λ��mm��
typedef struct __RANDOM_INFO
{
	bool    UseRandomRegion; // �Ƿ�ʹ����������ӡ
	double	LeftRange;
	double	TopRange;
	double	ImageWidth;
	double	ImageHight;
}RANDOM_INFO, *LPRANDOM_INFO;

//MUTI_INFO	
typedef struct __MUTI_INFO
{
	unsigned int	CopyCount[MAX_DIRS];		// ������(��������С��1��ʱ��1ʹ��)
	float	Spacing[MAX_DIRS];		// ��ࣨ��λ��mm��
}MUTI_INFO, *LPMUTI_INFO;

//COLORBAR_INFO
typedef struct __COLORBAR_INFO
{
	unsigned int 	Width;				// ɫ������λ:mm��
	unsigned int	DistanceFromImg;	// ��ͼ��ľ��루��λ:mm��
	bool			Fixed;				// �Ƿ�̶�λ��
	unsigned int	FixedPosition;		// �̶���λ�ã���Ը�λλ�ã�����λ:mm��
	bool			bAllColor;			// �Ƿ�������ɫ
}COLORBAR_INFO, *LPCOLORBAR_INFO;

//WHITE CONTROL��ɫ���Ʋ���
typedef struct _WHITE_CONTROL
{
	bool			UseWhite;		//�Ƿ�ʹ�ð�ɫ	
	bool			SyncPrint;		//ͬ����ӡ��־1: ͬ��0:�첽
	unsigned int	WhitePosition;	//��ɫ��ӡλ��0: bottom 1: Top  2:Middle
	bool			bCWCMirror;     // �Ƿ�ʰײ�
	bool			bUseTwoFile;	// �Ƿ�ʹ�������ļ�(��ɫ�����ڶ����ļ�,[A.prt(��ɫ) + A.prt1(��ɫ)]����ʽ) 
}WHITE_CONTROL, *LPWHITE_CONTROL;

//VARNISH CONTROL ������Ʋ���
typedef struct _VARNISH_CONTROL
{
	bool UseVarnish;    // �Ƿ�ʹ������	
	bool SyncUV;		// ͬ��UV����
	bool SyncPrint;	    // ͬ�������ӡ
}VARNISH_CONTROL, *LPVARNISH_CONTROL;

// �µ㲹��
typedef struct _tagJammedDotPara
{
	short*	pHeadNozzleStatusBuf[MAX_COLORS];	//������ͷ�����״̬��Ϣbuf������ʾû��������ʾ����
	short	iHeadPerSingleColor;				//����ɫʵ��װ�˼�����ͷ
}SJammedDotPara;

///////////////////////////////////////////////////////////////////////////////////////
typedef struct __SMART_PRINT_INFO
{
	long	StartOffset;     // ��ʼλ��
	long	EndOffset;		 // ����λ��
	bool	NeedJumpPrintY;  // �Ƿ���Ҫ��Pass
}SMART_PRINT_INFO, *LPSMART_PRINT_INFO;

typedef struct __CUR_PASS_INFO
{
	int					StepDistance;	//��ǰPass������,��λDot
	int					Modify;			//��ǰPass����Modify������X����
	SMART_PRINT_INFO	SmartPrintInfo;
}CUR_PASS_INFO, *LPCUR_PASS_INFO;

typedef struct  DOUBLE_FACE_PRINT_INFO_TAG
{
	float OffsetVertical[DIR_MAX];
	float OffsetHorizontal;
	bool	UseDoubleFacePrint;
}DOUBLE_FACE_PRINT_INFO;

typedef struct  REVIEW_COLOR_STRUCT_INFO_TAG
{
	unsigned char		C;
	unsigned char		M;
	unsigned char		Y;
	unsigned char		K;
	unsigned int	color;
}REVIEW_COLOR_STRUCT_INFO, *LPREVIEW_COLOR_STRUCT_INFO;

typedef struct __tagSIZE
{
	long        cx;
	long        cy;
} SIZE_Q, *PSIZE_Q, *LPSIZE_Q;

//HEAD_INFO:
typedef struct __HEAD_INFO
{
	unsigned int		uiNozzle;					// ÿ����ͷ��������
	unsigned int		uiUseNozzle;				// ʵ��ÿ��ʹ�õ������
	unsigned int		uiHeadType;					// ��ͷ����

	unsigned int		uiHeadDPI[MAX_DIRS];		// ��ͷ����ֱ���
	unsigned int		uiHeadsPerColor;			// ÿ����ͷ����ͷ����
	unsigned int		uiPixelPerByte;				// ÿ�ֽڱ�ʾ��������1bit:8, 2bit:4��

	float			fGroupOverlap;				// Y����ͷ�غϵ㣨��ֱ������Ч�� ��ֵΪ�غϣ���ֵΪ�ֿ���

	//int         nNozzleStrip;					// ��ͷб�����
	//int         nHeadColStrip[4];				// ��㷽��-1:����㣬0������㣬1������㣩
}HEAD_INFO, *LPHEAD_INFO;

//MACH_INFO:
typedef struct __MACH_INFO
{
	int					nMachineColorCount;		// ������ɫ��
	MACH_COLORTYPE		eMachineColorType;      // ������ɫ����
	int					nMachineGroupCount;		// ��ͷ������
	MACH_GROUPTYPE		eMachineGroupType;		// ��ͷ�����з�ʽ
	int					nMachineChannelCount;	// �ϼ�ͨ������Heads * HeadsPerColor * Group)

	int					nEncodeDPI[MAX_DIRS];	// X/Y ��դ�ͱ����̵�DPI
}MACH_INFO, *LPMACH_INFO;

//CHANNEL_INFO
typedef struct __CHANNEL_INFO
{
	int		iGroup;                         // ��No.
	int 	iColor;							// ͨ����Ӧ����ɫNo.
	int		iIndex;							// ͨ����Ӧ����ͷ�����
	bool	bUse;							// �Ƿ�ʹ��

	int		XStandOffset[DIR_MAX];			// X���׼ƫ��
	int		XOffset[DIR_MAX];				// X��ƫ��
	int		XInchingOffset[DIR_MAX];		// X��ƫ��΢��

	int		YStandOffset;					// ��׼ƫ�ƣ�Ĭ��0��
	int		YOffset;						// ��ͷY��ƫ��

	//int		iReadJumpRow;					// 
	int		nInkColors;						// ī��(0~ 100)
	int		bInvert;						// �Ƿ�ת����
}CHANNEL_INFO, *LPCHANNEL_INFO;


//Special image process
typedef struct __SPECIAL_PROCESS
{
	bool	UseFeather;
	bool	UseBlock;
	bool	UseSuperBlock;

	int		BlockSize;
	int     BlockMode;
	int     SuperBlockSize[4];
	int     SuperBlockMode;
	int     SuperBlockType;
	int     SuperBlockLayer;
	int     SuperBlockFeatherLevel;
	double  SuperBlockFeatherGamma;
	int     SuperBlockNoiseRange;

	bool	bSetSuperBlock;
	bool    bSuperBlockAddInk;
	bool    bSuperBlockDouble;

	// ��������ɨ��ʽ�մɻ��ã���Pass��
	bool	UseLittleFeather; 	//(�Ƿ�ʹ��С��)
	unsigned int	FeatherSize; 		//(�𻯴�С)

	// �µ㲹������
	bool	UseSameHeadCompansate[MAX_COLORS];
	SJammedDotPara sJammedDotPara[MAX_COLORS];
	int     JammedKCMYValue[4][MAX_COLORS];
	float	OtherHeadCoefficient[MAX_COLORS][MAX_COLORS];

	// ���
	//int		NoisePercent[MAX_COLORS][MAX_NOIZE_UNIT];//m_iNoisePercent[][0]����ת��Ϊ�͵İٷֱȣ�m_iNoisePercent[][1]����ת��Ϊ�͵İٷֱȣ�m_iNoisePercent[][2]����ת��Ϊ�͵İٷֱȣ�

}SPECIAL_PROCESS, LPSPECIAL_PROCESS;


typedef struct __PROCESS_PARAM
{
	//////////////////////////////////////////////////////////////////////////
	// OUT
	int	DotPerModify;				// Dot��ƫ��ֵ
	int	StepOffsetPassMode;     	// ���㴦����Pass����Ӧ��PassMode
	int	FeatherBlockPassMode;		// ���㴦����Pass��
	int	nNextGroupOffsetPass;		// Group��ƫ��Pass��
	int nNextGroupOffsetLine;		// Group��ƫ������
	unsigned int TotalPrintNum;				//��ӡpass����
	double	YDPIRatio;				// Y��DPI����ϵ��
	SIZE_Q	PrintSize;				//��ӡ�ߴ磬��λ��DOT����ʾ��ӡ������ܿ��/�߶ȣ�����ƫ�Ʋ��ף�

	//////////////////////////////////////////////////////////////////////////
	// IN
	PRT_IMG_TYPE    ImageType;					// ͼ������
	unsigned int	PassMode;			// 1Pass, 2Pass,  3Pass, 4Pass, 6Pass 8Pass, 12Pass, 16Pass
	unsigned int	PrintMode;			//Normal, Multi, Regin(���������������)
	wchar_t*		FilePath;					//��ӡ�ļ�·��
	REGIN_INFO		ReginInfo;					//�����ӡ���Ʋ���
	MUTI_INFO		MutiInfo;					//�����ӡ���Ʋ���

	COLORBAR_INFO	ColorBarInfo;				//ɫ����ӡ����
	WHITE_CONTROL	WhiteCtrl;					// ��ɫ��ӡ���Ʋ���
	VARNISH_CONTROL VarnishCtrl;				// ���ʹ�ӡ���Ʋ���

	SPECIAL_PROCESS	SpecialProcess;	            // ���⴦��

	bool  			AddColorBar;					// �Ƿ����ColorBar
	bool			MirrorPrint;				// �Ƿ���
	bool			YPrintDir;					// �Ƿ����ӡ
	bool			DoubleStrike;				// �Ƿ�����˫��
	bool			SingleDirPrint;				// �Ƿ����ӡ
	bool			PrintDir[MAX_DIRS];			// ��ӡ����
	bool			SmartPrint;					// �Ƿ����״�ӡ
	//BOOL          bUseDoubleGroup;			// �Ƿ�ʹ��˫��
	//BOOL			bGroupUse[MAX_GROUPS];	// ��ͷ�鹤������
	DOUBLE_FACE_PRINT_INFO DoubleFacePrintInfo; // ˫������Ʋ���	(IN)RANDOM_INFO	RandomRegionInfo;		// ��������ӡ
	bool 		    bUseRegionPrint;		    // �Ƿ�ͬʱʹ�������ӡ

	//BOOL			bUseMutiPrt;				// �Ƿ���ļ���ӡ
	//LPCTSTR		ExtendFiles;				// ���ļ�ͬʱ��ӡʱ���ļ���

}PROCESS_PARAM, *LPPROCESS_PARAM;


//PRINTER��ӡ��ϵͳ�����ṹ
typedef  struct  __PRINTER
{
	//Basic:
	//UINT		MachineColor;                               // ��ɫ����	
	//UINT		MachineGroup;                               // ��ͷ��
	//UINT		MachineChanel;                              // ͨ����
	//UINT		MachineCombination;                         // ��ͷ�װ���ͷ����
	//UINT		MachineHeadArrange;                         // ��ͷ����(TRUEΪ�������У�FALSEΪ��������)

	//UINT		ColorCount;									// ��ɫ��
	//UINT		HeadsPerColor;								// ��ͷ

	MACH_INFO	MachineInfo;								// �������Ͷ���
	HEAD_INFO	HeadInfo;									// ��ͷ��Ϣ

	CHANNEL_INFO Chanel[MAX_CHANELS];						//ͨ����Ϊÿһ����ͷ�н���һ��Chanel����
	//int         YOverlapOffset[MAX_PASS_MODES];             // ˫����ͷ��ɫ����

	//////////////////////////////////////////////////////////////////////////
	// Ԥ��ͼ������
	bool nUseCustomReview;						                    // �Ƿ�ʹ���Զ���Ԥ��
	int nReviewColorNumber;						                    // Ԥ��ͼ��ɫ��
	REVIEW_COLOR_STRUCT_INFO listReviewColorInfo[MAX_COLORS];       // Ԥ����ɫ����
	//////////////////////////////////////////////////////////////////////////

	// ��ͷ��ز���
	//		��ɫͨ��ӳ��)
	int     nColorIndex[MAX_COLORS];			// ��ɫͨ��ӳ���
	int     nFileColorIndex[MAX_COLORS];		// �ļ���ɫͨ��ӳ���
	int     nChannelColorIndex[MAX_COLORS];		// ͨ����ɫͨ��ӳ���

	// ����8�����˳��
	bool   bHeadPosLow[8];					// �װ�ߵʹ���
	int     bHeadOrder[8];					// ��ͷ˳����ʱ������
	double  fHeadOrder[8];					// ��ͷ˳����ʱ������
	/// -- End add

}PRINTER, *LPPRINTER;

#endif // SYSDEF_H