/*******************************************************************
*
*    DESCRIPTION:
*      ailia Speech Util
*    AUTHOR:
*      ax Inc.
*    DATE:2022/12/20
*
*******************************************************************/

#include "ailia_speech.h"
#include "ailia_audio.h"
#include "ailia_tokenizer.h"
#include "ailia.h"

inline AILIASpeechApiCallback ailiaSpeechUtilGetCallback(void){
	AILIASpeechApiCallback callback;
	callback.ailiaAudioGetFrameLen = ailiaAudioGetFrameLen;
	callback.ailiaAudioGetMelSpectrogram = ailiaAudioGetMelSpectrogram;
	callback.ailiaAudioResample = ailiaAudioResample;
	callback.ailiaAudioGetResampleLen = ailiaAudioGetResampleLen;

	callback.ailiaTokenizerCreate = ailiaTokenizerCreate;
	callback.ailiaTokenizerOpenModelFileA = ailiaTokenizerOpenModelFileA;
	callback.ailiaTokenizerOpenModelFileW = ailiaTokenizerOpenModelFileW;
	callback.ailiaTokenizerEncode = ailiaTokenizerEncode;
	callback.ailiaTokenizerGetTokenCount = ailiaTokenizerGetTokenCount;
	callback.ailiaTokenizerGetTokens = ailiaTokenizerGetTokens;
	callback.ailiaTokenizerDecode = ailiaTokenizerDecode;
	callback.ailiaTokenizerGetTextLength = ailiaTokenizerGetTextLength;
	callback.ailiaTokenizerGetText = ailiaTokenizerGetText;
	callback.ailiaTokenizerDestroy = ailiaTokenizerDestroy;
	callback.ailiaTokenizerUtf8ToUtf32 = ailiaTokenizerUtf8ToUtf32;
	callback.ailiaTokenizerUtf32ToUtf8 = ailiaTokenizerUtf32ToUtf8;

	callback.ailiaCreate = ailiaCreate;
	callback.ailiaOpenWeightFileA = ailiaOpenWeightFileA;
	callback.ailiaOpenWeightFileW = ailiaOpenWeightFileW;
	callback.ailiaOpenWeightMem = ailiaOpenWeightMem;
	callback.ailiaSetMemoryMode = ailiaSetMemoryMode;
	callback.ailiaDestroy = ailiaDestroy;
	callback.ailiaUpdate = ailiaUpdate;
	callback.ailiaGetBlobIndexByInputIndex = ailiaGetBlobIndexByInputIndex;
	callback.ailiaGetBlobIndexByOutputIndex = ailiaGetBlobIndexByOutputIndex;
	callback.ailiaGetBlobData = ailiaGetBlobData;
	callback.ailiaSetInputBlobData = ailiaSetInputBlobData;
	callback.ailiaSetInputBlobShape = ailiaSetInputBlobShape;
	callback.ailiaGetBlobShape = ailiaGetBlobShape;
	callback.ailiaGetErrorDetail = ailiaGetErrorDetail;
	callback.ailiaCopyBlobData = ailiaCopyBlobData;
	callback.ailiaGetEnvironment = ailiaGetEnvironment;
	return callback;
}
