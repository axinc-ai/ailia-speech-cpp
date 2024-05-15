/**
 * \~japanese
 * @file ailia_speech.h
 * @brief ailia Speech AI音声認識 ライブラリ
 * @copyright AXELL CORPORATION, ax Inc.
 * @date 2024/01/13
 */

#ifndef INCLUDED_AILIA_SPEECH
#define INCLUDED_AILIA_SPEECH

/* エラーコードと構造体 */

#include "ailia.h"
#include "ailia_tokenizer.h"

/* 呼び出し規約 */

#if defined(_WIN64) || defined(_M_X64) || defined(__amd64__) || defined(__x86_64__) || defined(__APPLE__) || \
	defined(__ANDROID__) || defined(ANDROID) || defined(__linux__) || defined(NN_NINTENDO_SDK)
#define AILIA_API
#else
#define AILIA_API __stdcall
#endif

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 * モデルタイプ定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_TINY
 * @brief Whisper Tiny model
 *
 * \~english
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_TINY
 * @brief Whisper Tiny model
 */
#define AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_TINY (0)

/**
 * \~japanese
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_BASE
 * @brief Whisper Base model
 *
 * \~english
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_BASE
 * @brief Whisper Base model
 */
#define AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_BASE (1)

/**
 * \~japanese
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_SMALL
 * @brief Whisper Small model
 *
 * \~english
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_SMALL
 * @brief Whisper Small model
 */
#define AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_SMALL (2)

/**
 * \~japanese
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_MEDIUM
 * @brief Whisper Medium model
 *
 * \~english
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_MEDIUM
 * @brief Whisper Medium model
 */
#define AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_MEDIUM (3)

/**
 * \~japanese
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_LARGE
 * @brief Whisper Large model
 *
 * \~english
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_LARGE
 * @brief Whisper Large model
 */
#define AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_LARGE (4)

/**
 * \~japanese
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_LARGE_V3
 * @brief Whisper Large V3 model
 *
 * \~english
 * @def AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_LARGE_V3
 * @brief Whisper Large V3 model
 */
#define AILIA_SPEECH_MODEL_TYPE_WHISPER_MULTILINGUAL_LARGE_V3 (5)

/****************************************************************
 * タスク定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_TASK_TRANSCRIBE
 * @brief 音声のテキスト化を行います
 *
 * \~english
 * @def AILIA_SPEECH_TASK_TRANSCRIBE
 * @brief Transcribe mode
 */
#define AILIA_SPEECH_TASK_TRANSCRIBE (0)

/**
 * \~japanese
 * @def AILIA_SPEECH_TASK_TRANSLATE
 * @brief 音声のテキスト化と翻訳を行います
 *
 * \~english
 * @def AILIA_SPEECH_TASK_TRANSLATE
 * @brief Translate mode
 */
#define AILIA_SPEECH_TASK_TRANSLATE (1)

/****************************************************************
 * 制約定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_CONSTRAINT_CHARACTERS
 * @brief 文字の制約を行います。
 *
 * \~english
 * @def AILIA_SPEECH_CONSTRAINT_CHARACTERS
 * @brief Constraint by characters
 */
#define AILIA_SPEECH_CONSTRAINT_CHARACTERS (0)

/**
 * \~japanese
 * @def AILIA_SPEECH_CONSTRAINT_WORDS
 * @brief 単語の制約を行います。単語はカンマで区切ります。
 *
 * \~english
 * @def AILIA_SPEECH_CONSTRAINT_WORDS
 * @brief Constraint by words. Separate words with commas.
 */
#define AILIA_SPEECH_CONSTRAINT_WORDS (1)

/****************************************************************
 * フラグ定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_FLAG_NONE
 * @brief フラグを設定しません
 *
 * \~english
 * @def AILIA_SPEECH_FLAG_NONE
 * @brief Default flag
 */
#define AILIA_SPEECH_FLAG_NONE (0)

/**
 * \~japanese
 * @def AILIA_SPEECH_FLAG_LIVE
 * @brief ライブ変換モードを有効にします
 *
 * \~english
 * @def AILIA_SPEECH_FLAG_LIVE
 * @brief Enable live transcribe mode
 */
#define AILIA_SPEECH_FLAG_LIVE (1)

/****************************************************************
 * VAD定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_VAD_TYPE_SILERO
 * @brief SileroVAD
 *
 * \~english
 * @def AILIA_SPEECH_VAD_TYPE_SILERO
 * @brief SileroVAD
 */
#define AILIA_SPEECH_VAD_TYPE_SILERO (0)

/****************************************************************
 * 辞書定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_DICTIONARY_TYPE_REPLACE
 * @brief 置換辞書
 *
 * \~english
 * @def AILIA_SPEECH_DICTIONARY_TYPE_REPLACE
 * @brief Dictionary for replace
 */
#define AILIA_SPEECH_DICTIONARY_TYPE_REPLACE (0)

/****************************************************************
 * 後処理定義
 **/

/**
 * \~japanese
 * @def AILIA_SPEECH_POST_PROCESS_TYPE_T5
 * @brief T5
 *
 * \~english
 * @def AILIA_SPEECH_POST_PROCESS_TYPE_T5
 * @brief T5
 */
#define AILIA_SPEECH_POST_PROCESS_TYPE_T5 (0)

/**
 * \~japanese
 * @def AILIA_SPEECH_POST_PROCESS_TYPE_FUGUMT_EN_JA
 * @brief FuguMT EN JA
 * @details
 * 最大トークン長は384です。これを超えた場合はStripされます。
 *
 * \~english
 * @def AILIA_SPEECH_POST_PROCESS_TYPE_FUGUMT_EN_JA
 * @brief FuguMT EN JA
 * @details
 * The maximum token length is 384. If exceeded, it will be stripped.
 */
#define AILIA_SPEECH_POST_PROCESS_TYPE_FUGUMT_EN_JA (1)

/**
 * \~japanese
 * @def AILIA_SPEECH_POST_PROCESS_TYPE_FUGUMT_JA_EN
 * @brief FuguMT JA EN
 * @details
 * 最大トークン長は512です。これを超えた場合はStripされます。
 *
 * \~english
 * @def AILIA_SPEECH_POST_PROCESS_TYPE_FUGUMT_EN_JA
 * @brief FuguMT JA EN
 * @details
 * The maximum token length is 512. If exceeded, it will be stripped.
 */
#define AILIA_SPEECH_POST_PROCESS_TYPE_FUGUMT_JA_EN (2)

/****************************************************************
 * APIコールバック定義
 **/

//接続が必要なAPI

#if defined(_WIN32) && !defined(_WIN64)
	#define AILIA_SPEECH_USER_API __stdcall
#else
	#define AILIA_SPEECH_USER_API
#endif

// ailia.audio API
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_AUDIO_GET_FRAME_LEN)(int*, int, int, int, int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_AUDIO_GET_MEL_SPECTROGRAM)(void*, const void*, int, int, int, int, int, int, int, int, float, int, float, float, int, int, int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_AUDIO_RESAMPLE)(void*, const void*, int, int, int, int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_AUDIO_GET_RESAMPLE_LEN)(int*, int, int, int);

// ailia.tokenizer API
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_CREATE)(struct AILIATokenizer** , int, int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_OPEN_MODEL_FILE_A)(struct AILIATokenizer* , const char *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_OPEN_MODEL_FILE_W)(struct AILIATokenizer* , const wchar_t *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_ENCODE)(struct AILIATokenizer* , const char *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TOKEN_COUNT)(struct AILIATokenizer* , unsigned int*);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TOKENS)(struct AILIATokenizer* , int* , unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_DECODE)(struct AILIATokenizer* , const int *, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TEXT_LENGTH)(struct AILIATokenizer* , unsigned int*);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TEXT)(struct AILIATokenizer* , char* , unsigned int);
typedef void(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_DESTROY)(struct AILIATokenizer*);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_UTF8_TO_UTF32)(unsigned int* , unsigned int* , const char* , unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_TOKENIZER_UTF32_TO_UTF8)(char* , unsigned int* , unsigned int);

// ailia API
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_CREATE)(struct AILIANetwork **, int, int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_OPEN_WEIGHT_FILE_A)(struct AILIANetwork *, const char *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_OPEN_WEIGHT_FILE_W)(struct AILIANetwork *, const wchar_t *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_OPEN_WEIGHT_MEM)(struct AILIANetwork *, const void *, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_SET_MEMORY_MODE)(struct AILIANetwork*, unsigned int);
typedef void(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_DESTROY)(struct AILIANetwork *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_UPDATE)(struct AILIANetwork *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_GET_BLOB_INDEX_BY_INPUT_INDEX)(struct AILIANetwork *, unsigned int *, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_GET_BLOB_INDEX_BY_OUTPUT_INDEX)(struct AILIANetwork *, unsigned int *, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_GET_BLOB_DATA)(struct AILIANetwork *, void*, unsigned int, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_SET_INPUT_BLOB_DATA)(struct AILIANetwork *, const void*, unsigned int, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_SET_INPUT_BLOB_SHAPE)(struct AILIANetwork *, const AILIAShape*, unsigned int, unsigned int);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_GET_BLOB_SHAPE)(struct AILIANetwork *, AILIAShape*, unsigned int, unsigned int);
typedef const char*(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_GET_ERROR_DETAIL)(struct AILIANetwork *);
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_COPY_BLOB_DATA)(struct AILIANetwork* dst_net, unsigned int dst_blob_idx, struct AILIANetwork* src_net, unsigned int src_blob_idx);
typedef int (AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_AILIA_GET_ENVIRONMENT)(AILIAEnvironment** env, unsigned int env_idx, unsigned int version);


/**
* \~japanese
* @def AILIA_SPEECH_API_CALLBACK_VERSION
* @brief 構造体バージョン
*
* \~english
* @def AILIA_SPEECH_API_CALLBACK_VERSION
* @brief Struct version
*/
#define AILIA_SPEECH_API_CALLBACK_VERSION (6)

/* APIコールバック関数構造体 */
typedef struct _AILIASpeechApiCallback {
	AILIA_SPEECH_USER_API_AILIA_AUDIO_GET_FRAME_LEN  ailiaAudioGetFrameLen;
	AILIA_SPEECH_USER_API_AILIA_AUDIO_GET_MEL_SPECTROGRAM ailiaAudioGetMelSpectrogram;
	AILIA_SPEECH_USER_API_AILIA_AUDIO_RESAMPLE ailiaAudioResample;
	AILIA_SPEECH_USER_API_AILIA_AUDIO_GET_RESAMPLE_LEN ailiaAudioGetResampleLen;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_CREATE ailiaTokenizerCreate;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_OPEN_MODEL_FILE_A ailiaTokenizerOpenModelFileA;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_OPEN_MODEL_FILE_W ailiaTokenizerOpenModelFileW;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_ENCODE ailiaTokenizerEncode;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TOKEN_COUNT ailiaTokenizerGetTokenCount;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TOKENS ailiaTokenizerGetTokens;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_DECODE ailiaTokenizerDecode;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TEXT_LENGTH ailiaTokenizerGetTextLength;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_GET_TEXT ailiaTokenizerGetText;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_DESTROY ailiaTokenizerDestroy;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_UTF8_TO_UTF32 ailiaTokenizerUtf8ToUtf32;
	AILIA_SPEECH_USER_API_AILIA_TOKENIZER_UTF32_TO_UTF8 ailiaTokenizerUtf32ToUtf8;
	AILIA_SPEECH_USER_API_AILIA_CREATE ailiaCreate;
	AILIA_SPEECH_USER_API_AILIA_OPEN_WEIGHT_FILE_A ailiaOpenWeightFileA;
	AILIA_SPEECH_USER_API_AILIA_OPEN_WEIGHT_FILE_W ailiaOpenWeightFileW;
	AILIA_SPEECH_USER_API_AILIA_OPEN_WEIGHT_MEM ailiaOpenWeightMem;
	AILIA_SPEECH_USER_API_AILIA_SET_MEMORY_MODE ailiaSetMemoryMode;
	AILIA_SPEECH_USER_API_AILIA_DESTROY ailiaDestroy;
	AILIA_SPEECH_USER_API_AILIA_UPDATE ailiaUpdate;
	AILIA_SPEECH_USER_API_AILIA_GET_BLOB_INDEX_BY_INPUT_INDEX ailiaGetBlobIndexByInputIndex;
	AILIA_SPEECH_USER_API_AILIA_GET_BLOB_INDEX_BY_OUTPUT_INDEX ailiaGetBlobIndexByOutputIndex;
	AILIA_SPEECH_USER_API_AILIA_GET_BLOB_DATA ailiaGetBlobData;
	AILIA_SPEECH_USER_API_AILIA_SET_INPUT_BLOB_DATA ailiaSetInputBlobData;
	AILIA_SPEECH_USER_API_AILIA_SET_INPUT_BLOB_SHAPE ailiaSetInputBlobShape;
	AILIA_SPEECH_USER_API_AILIA_GET_BLOB_SHAPE ailiaGetBlobShape;
	AILIA_SPEECH_USER_API_AILIA_GET_ERROR_DETAIL ailiaGetErrorDetail;
	AILIA_SPEECH_USER_API_AILIA_COPY_BLOB_DATA ailiaCopyBlobData;
	AILIA_SPEECH_USER_API_AILIA_GET_ENVIRONMENT ailiaGetEnvironment;
} AILIASpeechApiCallback;

/****************************************************************
 * 中間情報取得コールバック
 **/

/**
 * \~japanese
 * @brief 推論の途中の状況を通知します。
 * @param handle ailiaSpeechSetIntermediateCallbackに指定したhandle
 * @param text   推論の途中のテキスト
 * @return
 *   0を返すと継続、0以外を返すと推論を中断します。
 *
 * \~english
 * @brief Notify the status during the inference.
 * @param handle handle specified in ailiaSpeechSetIntermediateCallback
 * @param text   text in the middle of reasoning
 * @return
 *   Return 0 to continue, non-zero to abort inference.
 */
typedef int(AILIA_SPEECH_USER_API* AILIA_SPEECH_USER_API_INTERMEDIATE_CALLBACK)(void *handle, const char *text);

/****************************************************************
 * ネットワークオブジェクトのインスタンス
 **/

struct AILIASpeech;

/**
* \~japanese
* @def AILIA_SPEECH_TEXT_VERSION
* @brief 構造体バージョン
*
* \~english
* @def AILIA_SPEECH_TEXT_VERSION
* @brief Struct version
*/
#define AILIA_SPEECH_TEXT_VERSION (2)

typedef struct _AILIASpeechText{
const char * text;
float time_stamp_begin;
float time_stamp_end;
unsigned int person_id;	// Reserved
const char * language;
float confidence;
}AILIASpeechText;

/****************************************************************
 * Speech2Text API
 **/

/**
 * \~japanese
 * @brief ネットワークオブジェクトを作成します。
 * @param net ネットワークオブジェクトポインタへのポインタ
 * @param env_id 計算に利用する推論実行環境のID( ailiaGetEnvironment() で取得)  \ref AILIA_ENVIRONMENT_ID_AUTO にした場合は自動で選択する
 * @param num_thread スレッド数の上限(  \ref AILIA_MULTITHREAD_AUTO  にした場合は自動で設定)
 * @param memory_mode メモリモード(AILIA_MEMORY_MODE_*)
 * @param task AILIA_SPEECH_TASK_*
 * @param flag AILIA_SPEECH_FLAG_*の論理和
 * @param api_callback ailiaのAPIへのコールバック
 * @param version AILIA_SPEECH_API_CALLBACK_VERSION
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ネットワークオブジェクトを作成します。
 *
 * \~english
 * @brief Creates a network instance.
 * @param net A pointer to the network instance pointer
 * @param env_id The ID of the inference backend used for computation (obtained by  ailiaGetEnvironment() ). It is selected automatically if  \ref AILIA_ENVIRONMENT_ID_AUTO  is specified.
 * @param num_thread The upper limit on the number of threads (It is set automatically if  \ref AILIA_MULTITHREAD_AUTO
 * @param memory_mode The memory mode (AILIA_MEMORY_MODE_*)
 * @param task AILIA_SPEECH_TASK_*
 * @param flag OR of AILIA_SPEECH_FLAG_*
 * @param api_callback The callback for ailia API
 * @param version AILIA_SPEECH_API_CALLBACK_VERSION
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Creates a network instance.
 */
int AILIA_API ailiaSpeechCreate(struct AILIASpeech** net, int env_id, int num_thread, int memory_mode, int task, int flags, AILIASpeechApiCallback callback, int version);

/**
 * \~japanese
 * @brief モデルを指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder_path onnxファイルのパス名(MBSC)
 * @param decoder_path onnxファイルのパス名(MBSC)
 * @param model_type AILIA_SPEECH_MODEL_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set models into a network instance.
 * @param net A network instance pointer
 * @param encoder_path The path name to the onnx file (MBSC)
 * @param decoder_path The path name to the onnx file (MBSC)
 * @param model_type AILIA_SPEECH_MODEL_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenModelFileA(struct AILIASpeech* net, const char* encoder_path, const char* decoder_path, int model_type);

/**
 * \~japanese
 * @brief モデルを指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder_path onnxファイルのパス名(UTF16)
 * @param decoder_path onnxファイルのパス名(UTF16)
 * @param model_type AILIA_SPEECH_MODEL_TYPE_*
 * @param task AILIA_SPEECH_TASK_*
 * @param flag AILIA_SPEECH_FLAG_*の論理和
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set models into a network instance.
 * @param net A network instance pointer
 * @param encoder_path The path name to the onnx file (UTF16)
 * @param decoder_path The path name to the onnx file (UTF16)
 * @param model_type AILIA_SPEECH_MODEL_TYPE_*
 * @param task AILIA_SPEECH_TASK_*
 * @param flag OR of AILIA_SPEECH_FLAG_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenModelFileW(struct AILIASpeech* net, const wchar_t* encoder_path, const wchar_t* decoder_path, int model_type);

/**
 * \~japanese
 * @brief 無音検知に適用するVADモデルを指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param vad_path onnxファイルのパス名(MBSC)
 * @param vad_type AILIA_SPEECH_VAD_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set vad model for voice activity detection.
 * @param net A network instance pointer
 * @param vad_path The path name to the onnx file (MBSC)
 * @param vad_type AILIA_SPEECH_VAD_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenVadFileA(struct AILIASpeech* net, const char* vad_path, int vad_type);

/**
 * \~japanese
 * @brief 無音検知に適用するVADモデルを指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param vad_path onnxファイルのパス名(UTF16)
 * @param vad_type AILIA_SPEECH_VAD_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set vad model for voice activity detection.
 * @param net A network instance pointer
 * @param vad_path The path name to the onnx file (UTF16)
 * @param vad_type AILIA_SPEECH_VAD_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenVadFileW(struct AILIASpeech* net, const wchar_t* vad_path, int vad_type);

/**
 * \~japanese
 * @brief 誤り訂正辞書を指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param dictionary_path 辞書ファイルのパス名(MBSC)
 * @param dictionary_type AILIA_SPEECH_DICTIONARY_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set dictionary for error correction.
 * @param net A network instance pointer
 * @param dictionary_path The path name to the dictionary file (MBSC)
 * @param dictionary_type AILIA_SPEECH_DICTIONARY_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenDictionaryFileA(struct AILIASpeech* net, const char* dictionary_path, int dictionary_type);

/**
 * \~japanese
 * @brief 誤り訂正辞書を指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param dictionary_path 辞書ファイルのパス名(UTF16)
 * @param dictionary_type AILIA_SPEECH_DICTIONARY_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set dictionary for error correction.
 * @param net A network instance pointer
 * @param dictionary_path The path name to the dictionary file (UTF16)
 * @param dictionary_type AILIA_SPEECH_DICTIONARY_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenDictionaryFileW(struct AILIASpeech* net, const wchar_t* dictionary_path, int dictionary_type);

/**
 * \~japanese
 * @brief 後処理知に適用するAIモデルを指定します。(MBSC)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder_path onnxファイルのパス名(MBSC)
 * @param decoder_path onnxファイルのパス名(MBSC)
 * @param source_path Tokenizerのmodelファイルのパス名(MBSC)
 * @param target_path Tokenizerのmodelファイルのパス名(MBSC)
 * @param prefix      T5のprefix (UTF8)、FuguMTの場合はNULL
 * @param post_process_type AILIA_SPEECH_POST_PROCESS_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set AI model for post process (MBSC)
 * @param net A network instance pointer
 * @param encoder_path The path name to the onnx file (MBSC)
 * @param decoder_path The path name to the onnx file (MBSC)
 * @param source_path The path name to the tokenizer model file (MBSC)
 * @param target_path The path name to the tokenizer model file (MBSC)
 * @param prefix      The prefix of T5 (UTF8), NULL for FuguMT
 * @param post_process_type AILIA_SPEECH_POST_PROCESS_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenPostProcessFileA(struct AILIASpeech* net, const char* encoder_path, const char* decoder_path, const char * source_path, const char * target_path, const char * prefix, int post_process_type);

/**
 * \~japanese
 * @brief 後処理知に適用するAIモデルを指定します。(UTF16)
 * @param net ネットワークオブジェクトポインタ
 * @param encoder_path onnxファイルのパス名(UTF16)
 * @param decoder_path onnxファイルのパス名(UTF16)
 * @param source_path Tokenizerのmodelファイルのパス名(UTF16)
 * @param target_path Tokenizerのmodelファイルのパス名(UTF16)
 * @param prefix      T5のprefix (UTF8)、FuguMTの場合はNULL
 * @param post_process_type AILIA_SPEECH_POST_PROCESS_TYPE_*
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Set AI model for post process (UTF16)
 * @param net A network instance pointer
 * @param encoder_path The path name to the onnx file (UTF16)
 * @param decoder_path The path name to the onnx file (UTF16)
 * @param source_path The path name to the tokenizer model file (UTF16)
 * @param target_path The path name to the tokenizer model file (UTF16)
 * @param prefix      The prefix of T5 (UTF8), NULL for FuguMT
 * @param post_process_type AILIA_SPEECH_POST_PROCESS_TYPE_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechOpenPostProcessFileW(struct AILIASpeech* net, const wchar_t* encoder_path, const wchar_t* decoder_path, const wchar_t * source_path, const wchar_t * target_path, const char * prefix, int post_process_type);

/**
 * \~japanese
 * @brief 音声をキューに投入します。
 * @param net ネットワークオブジェクトポインタ
 * @param src PCMデータ（チャンネルインタリーブ、ステレオの場合はLRLR順、PCMは-1.0〜1.0のレンジ）
 * @param channels チャンネル数
 * @param samples チャンネルあたりのサンプル数
 * @param sampling_rate サンプリングレート（Hz）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Push PCM data to queue
 * @param net A network instance pointer
 * @param src The input pcm data (channel interleave, LRLR order for stereo, -1.0 to 1.0 pcm range)
 * @param channels The number of pcm channels
 * @param samples The number of pcm samples per channel
 * @param sampling_rate The sampling rate (Hz)
  * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API
ailiaSpeechPushInputData(struct AILIASpeech* net, const float* src, unsigned int channels, unsigned int samples, unsigned int sampling_rate);

/**
 * \~japanese
 * @brief 音声のキューへの投入を終了します。
 * @param net ネットワークオブジェクトポインタ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   音声ファイルの末尾であることを通知することで、30秒分のデータが存在しなくてもailiaSpeechBufferedが1を返すようになります。
 *   ailiaSpeechFinalizeInputDataを実行後、ailiaSpeechPushInputDataの実行前に、ailiaSpeechResetTranscribeStateを呼び出す必要があります。
 *
 * \~english
 * @brief Finalize input PCM data to queue
 * @param net A network instance pointer
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   By signaling the end of the audio file, ailiaSpeechBuffered will return 1 even if 30 seconds worth of data does not exist.
 *   You must call ailiaSpeechResetTranscribeState after executing ailiaSpeechFinalizeInputData and before executing ailiaSpeechPushInputData.
 */
int AILIA_API
ailiaSpeechFinalizeInputData(struct AILIASpeech* net);

/**
 * \~japanese
 * @brief 音声認識を行うために十分なデータが存在するかどうかを判定します。
 * @param net ネットワークオブジェクトポインタ
 * @param buffered 存在フラグ（1で存在、0で存在しない）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Determines if there is enough data to perform speech recognition.
 * @param net A network instance pointer
 * @param buffered Is data exist (1 : Exist, 0 : Not Exist)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaSpeechBuffered(struct AILIASpeech* net, unsigned int *buffered);

/**
 * \~japanese
 * @brief 全てのデータの処理が完了したかどうかを判定します。
 * @param net ネットワークオブジェクトポインタ
 * @param complete 完了フラグ（1で完了、0で完了していない）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Determines whether all data has been processed.
 * @param net A network instance pointer
 * @param complete Is processing complete (1 : Complete, 0 : Not Complete)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API
ailiaSpeechComplete(struct AILIASpeech* net, unsigned int *complete);

/**
 * \~japanese
 * @brief プロンプトの設定を行います。
 * @param net ネットワークオブジェクトポインタ
 * @param prompt promptとなるテキスト(UTF8)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す
 *
 * \~english
 * @brief Set prompt.
 * @param net A network instance pointer
 * @param prompt The text of prompt (UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API
ailiaSpeechSetPrompt(struct AILIASpeech* net, const char *prompt);

/**
 * \~japanese
 * @brief 制約の設定を行います。
 * @param net ネットワークオブジェクトポインタ
 * @param constraint 制約となるテキスト(UTF8)
 * @param type 制約モード (AILIA_SPEECH_CONSTRAINT_*)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す
 *
 * \~english
 * @brief Set constraint.
 * @param net A network instance pointer
 * @param constraint The text of constraint (UTF8)
 * @param type The type of constraint (AILIA_SPEECH_CONSTRAINT_*)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API
ailiaSpeechSetConstraint(struct AILIASpeech* net, const char *constraint, int type);

/**
 * \~japanese
 * @brief 言語設定を行います。
 * @param net ネットワークオブジェクトポインタ
 * @param language 言語コード（en, jaなど）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す
 * @details
 *   languageに"auto"を指定すると自動選択を行います。
 *
 * \~english
 * @brief Set language.
 * @param net A network instance pointer
 * @param language Language code (en, ja, etc)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If you set "auto" to language, language will automatically detected.
 */
int AILIA_API
ailiaSpeechSetLanguage(struct AILIASpeech* net, const char *language);

/**
 * \~japanese
 * @brief 無音判定の閾値を設定します。
 * @param net ネットワークオブジェクトポインタ
 * @param silent_threshold  有音判定のしきい値
 * @param speech_sec    有音区間の時間（秒数）
 * @param no_speech_sec 無音区間の時間（秒数）
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す
 * @details
 *   有音区間が一定以上存在する場合に無音区間が一定時間以上続いた場合に30secを待たずに滞留しているバッファを処理します。
 *
 * \~english
 * @brief Set silent threshold.
 * @param net A network instance pointer
 * @param silent_threshold  volume threshold
 * @param speech_sec    speech time
 * @param no_speech_sec no_speech time
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If there are more than a certain number of sounded sections, and if the silent section lasts for a certain amount of time or more,
 *   the remaining buffer is processed without waiting for 30 seconds.
 */
int AILIA_API
ailiaSpeechSetSilentThreshold(struct AILIASpeech* net, float silent_threshold, float speech_sec, float no_speech_sec);

/**
 * \~japanese
 * @brief 認識の途中結果を取得するコールバックを設定します。
 * @param net ネットワークオブジェクトポインタ
 * @param callback コールバック
 * @param handle コールバックに渡されるハンドル
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   返値は解放する必要はありません。
 *   文字列の有効期間は次にailiaSpeechのAPIを呼ぶまでです。
 *
 * \~english
 * @brief Set a callback to get intermediate results of recognition.
 * @param net A network instance pointer
 * @param callback callback
 * @param handle handle for callback
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   The return value does not have to be released.
 *   The string is valid until the next ailiaSpeech API function is called.
 */
int AILIA_API
ailiaSpeechSetIntermediateCallback(struct AILIASpeech* net, AILIA_SPEECH_USER_API_INTERMEDIATE_CALLBACK callback, void *handle);

/**
 * \~japanese
 * @brief 音声認識を行います。
 * @param net ネットワークオブジェクトポインタ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   認識した結果はailiaSpeechGetText APIで取得します。
 *
 * \~english
 * @brief Speech recognition
 * @param net A network instance pointer
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the recognition result with ailiaSpeechGetText API.
 */
int AILIA_API
ailiaSpeechTranscribe(struct AILIASpeech* net);

/**
 * \~japanese
 * @brief 後処理を行います。
 * @param net ネットワークオブジェクトポインタ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   認識した結果はailiaSpeechGetText APIで取得します。
 *
 * \~english
 * @brief Execute post process
 * @param net A network instance pointer
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the recognition result with ailiaSpeechGetText API.
 */
int AILIA_API
ailiaSpeechPostProcess(struct AILIASpeech* net);

/**
 * \~japanese
 * @brief 認識したテキストの数を取得します。
 * @param net ネットワークオブジェクトポインタ
 * @param count テキストの数
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Get recognized text count
 * @param net A network instance pointer
 * @param count Text count
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API
ailiaSpeechGetTextCount(struct AILIASpeech* net, unsigned int *count);

/**
 * \~japanese
 * @brief 認識したテキストを取得します。
 * @param net ネットワークオブジェクトポインタ
 * @param text テキスト
 * @param version AILIA_SPEECH_TEXT_VERSION
 * @param idx テキストのインデックス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   返値は解放する必要はありません。
 *   文字列の有効期間は次にailiaSpeechのAPIを呼ぶまでです。
 *
 * \~english
 * @brief Get recognized text
 * @param net A network instance pointer
 * @param text Text
 * @param version AILIA_SPEECH_TEXT_VERSION
 * @param idx Text index
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   The return value does not have to be released.
 *   The string is valid until the next ailiaSpeech API function is called.
 */
int AILIA_API
ailiaSpeechGetText(struct AILIASpeech* net, AILIASpeechText *text, unsigned int version, unsigned int idx);

/**
 * \~japanese
 * @brief ポストプロセス対象のテキストを設定します。
 * @param net ネットワークオブジェクトポインタ
 * @param text テキスト
 * @param version AILIA_SPEECH_TEXT_VERSION
 * @param idx テキストのインデックス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   音声認識を使用せず、ポストプロセスのみを使用する場合に使用します。
 *   文字列は内部バッファにコピーされるため、呼び出し後に解放することができます。
 *   idxがailiaSpeechGetTextCountよりも大きい場合、自動的に内部バッファが拡張されます。
 *
 * \~english
 * @brief Set postprocess text
 * @param net A network instance pointer
 * @param text Text
 * @param version AILIA_SPEECH_TEXT_VERSION
 * @param idx Text index
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Used when using only post-processing without using speech recognition.
 *   Since the string is copied to the internal buffer, it can be released after the call.
 *   If idx is larger than ailiaSpeechGetTextCount, the internal buffer will be automatically expanded.
 */
int AILIA_API
ailiaSpeechSetText(struct AILIASpeech* net, const AILIASpeechText *text, unsigned int version, unsigned int idx);

/**
 * \~japanese
 * @brief ネットワークオブジェクトを破棄します。
 * @param net ネットワークオブジェクトポインタ
 *
 * \~english
 * @brief It destroys the network instance.
 * @param net A network instance pointer
 */
void AILIA_API ailiaSpeechDestroy(struct AILIASpeech* net);

/**
 * \~japanese
 * @brief ネットワークオブジェクトの内部状態を初期化します。
 * @param net ネットワークオブジェクトポインタ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   このAPIを呼び出すことで、前回のデコード結果などの内部状態を初期化します。
 *   このAPIを呼び出した後、モデルを再び開く必要はありません。
 *   ailiaSpeechOpenModelFile、ailiaSpeechSetIntermediateCallback、ailiaSpeechSetLanguage、ailiaSpeechSetSilentThreshold、ailiaSpeechSetPromptのステートは保持されます。
 *
 * \~english
 * @brief It resets the network instance.
 * @param net A network instance pointer
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   By calling this API, the internal state such as the previous decoding result is initialized.
 *   There is no need to reopen the model after calling this API.
 *   The states of ailiaSpeechOpenModelFile, ailiaSpeechSetIntermediateCallback, ailiaSpeechSetLanguage, ailiaSpeechSetSilentThreshold, ailiaSpeechSetPrompt are preserved.
 */
int AILIA_API ailiaSpeechResetTranscribeState(struct AILIASpeech* net);

/**
 * \~japanese
 * @brief エラーの詳細を返します
 * @param net   ネットワークオブジェクトポインタ
 * @return
 *   エラー詳細
 * @details
 *   返値は解放する必要はありません。
 *   文字列の有効期間は次にailiaSpeechのAPIを呼ぶまでです。
 *   モデルが暗号化されている場合は空文字を返します。
 *
 * \~english
 * @brief Returns the details of errors.
 * @param net   The network instance pointer
 * @return
 *   Error details
 * @details
 *   The return value does not have to be released.
 *   The string is valid until the next ailiaSpeech API function is called.
 *   If model is encrypted, this function returns empty string.
 */
const char* AILIA_API ailiaSpeechGetErrorDetail(struct AILIASpeech* net);

#ifdef UNICODE
#define ailiaSpeechOpenModelFile ailiaSpeechOpenModelFileW
#define ailiaSpeechOpenVadFile ailiaSpeechOpenVadFileW
#define ailiaSpeechOpenDictionaryFile ailiaSpeechOpenDictionaryFileW
#define ailiaSpeechOpenPostProcessFile ailiaSpeechOpenPostProcessFileW
#else
#define ailiaSpeechOpenModelFile ailiaSpeechOpenModelFileA
#define ailiaSpeechOpenVadFile ailiaSpeechOpenVadFileA
#define ailiaSpeechOpenDictionaryFile ailiaSpeechOpenDictionaryFileA
#define ailiaSpeechOpenPostProcessFile ailiaSpeechOpenPostProcessFileA
#endif

#ifdef __cplusplus
}
#endif
#endif /* !defined(INCLUDED_AILIA_SPEECH) */
