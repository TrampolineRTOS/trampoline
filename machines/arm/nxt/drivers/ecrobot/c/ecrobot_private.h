#ifndef _ECROBOT_PRIVATE_H_
#define _ECROBOT_PRIVATE_H_

#include "ecrobot_types.h"

typedef struct {
  U32 battery_state;
   U8 buttons_state;
} nxt_inputs;

typedef struct {
  S8 speed;
  U8 mode;
} nxt_outputs;

#define BTN1 0x01
#define BTN2 0x02
#define BTN3 0x04
#define BTN4 0x08
#define ENTER_PRESSED BTN1
#define STOP_PRESSED  BTN2
#define RUN_PRESSED   BTN3
#define EXIT_PRESSED  BTN4


/* 
 * WAV file format specification
 * <http://ccrma.stanford.edu/CCRMA/Courses/422/projects/WaveFormat/>
 */
/* linear PCM (data chunkID is "data") */
typedef struct {
	struct {
		U32 chunkID;
		U32 chunkSize;
		U32 format;
	} __attribute__((packed)) riff;

	struct {
		U32 chunkID;
		U32 chunkSize;
		U16 audioFormat;
		U16 numChannels;
		U32 sampleRate;
		U32 byteRate;
		U16 blockAlign;
		U16 bitsPerSample;
		U16 dummy; /* 2 bytes dummy */
	} __attribute__((packed)) fmt;

	struct {
		U32 chunkID;
		U32 chunkSize;
		U8  data[];
	} __attribute__((packed)) data;
} __attribute__((packed)) WAV;

/* linear PCM (data chunkID is "fact") */
typedef struct {
	struct {
		U32 chunkID;
		U32 chunkSize;
		U32 format;
	} __attribute__((packed)) riff;

	struct {
		U32 chunkID;
		U32 chunkSize;
		U16 audioFormat;
		U16 numChannels;
		U32 sampleRate;
		U32 byteRate;
		U16 blockAlign;
		U16 bitsPerSample;
		U16 dummy; /* 2 bytes dummy */
	} __attribute__((packed)) fmt;

	struct {
		U32 chunkID; /* fact */
		U32 chunkSize;
		U32 numSamples;
		U32 data_chunkID;
		U32 data_chunkSize;
		U8  data[];
	} __attribute__((packed)) data;
} __attribute__((packed)) WAV_FACT;

/* non-linear PCM */
typedef struct {
	struct {
		U32 chunkID;
		U32 chunkSize;
		U32 format;
	} __attribute__((packed)) riff;

	struct {
		U32 chunkID;
		U32 chunkSize;
		U16 audioFormat;
		U16 numChannels;
		U32 sampleRate;
		U32 byteRate;
		U16 blockAlign;
		U16 bitsPerSample;
		U16 dummy; /* 2 bytes dummy */
	} __attribute__((packed)) fmt;

	struct {
		U32 chunkID;
		U32 chunkSize;
		U8  data[];
	} __attribute__((packed)) data;
} __attribute__((packed)) WAV_NL;

#define WAV_HDR_SIZE	44
#define RIFF_CHUNK_ID	0x46464952  /* "RIFF" in little-endian form  */
#define RIFF_FORMAT		0x45564157  /* "WAVE" in little-endian form  */
#define FMT_CHUNK_ID	0x20746d66  /* "fmt " in little-endian form  */
#define DATA_CHUNK_ID   0x61746164  /* "data" in little-endian form  */
#define FACT_CHUNK_ID   0x74636166  /* "fact" in little-endian form  */


/*
 * BMP file format specification
 * <http://local.wasp.uwa.edu.au/~pbourke/dataformats/bmp/>
 */
typedef struct {
	struct {
		U16 type;             /* Magic identifier              */
		U32 size;             /* File size in bytes            */
		U16 reserved1;
		U16 reserved2;
		U32 offset;           /* Offset to image data in bytes */
	} __attribute__((packed)) fileHeader;

	struct {
		U32 size;             /* Header size in bytes          */
		S32 width;            /* Width of image                */
		S32 height;           /* Height of image               */
		U16 planes;           /* Number of colour planes       */
		U16 bits;             /* Bits per pixel                */
		U32 compression;      /* Compression type              */
		U32 imagesize;        /* Image size in bytes           */
		S32 xresolution;      /* Pixels per meter in x         */
		S32 yresolution;      /* Pixels per meter in y         */
		U32 ncolours;         /* Number of colours             */
		U32 importantcolours; /* Important colours             */
	} __attribute__((packed)) infoHeader;

	struct {
		U8 blue;
		U8 green;
		U8 red;
		U8 reserved;
	} __attribute__((packed)) rgb;
} __attribute__((packed)) BMP;

#define BM_TYPE 0x4d42 /* "BM" in little-endian form */


/* private common functions */
extern   U8 ecrobot_get_button_state(void);
extern void ecrobot_init_nxtstate(void);
extern void ecrobot_poll_nxtstate(void);
extern void ecrobot_setDeviceInitialized(void);

#endif
