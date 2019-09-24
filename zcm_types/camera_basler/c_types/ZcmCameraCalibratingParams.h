// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <stdint.h>
#include <stdlib.h>
#include <zcm/zcm_coretypes.h>
#include <zcm/zcm.h>

#ifndef _ZcmCameraCalibratingParams_h
#define _ZcmCameraCalibratingParams_h

#ifdef __cplusplus
extern "C" {
#endif

/**
 * =======================================================================================
 * @struct ZcmCameraCalibratingParams
 * @brief Калибровочные параметры для камеры...
 *
 */
typedef struct _ZcmCameraCalibratingParams ZcmCameraCalibratingParams;
struct _ZcmCameraCalibratingParams
{
    float      cam_mtx[3][3];
    float      distCoeff[5];
    float      rvec[3];
    float      tvec[3];
};

/**
 * Create a deep copy of a ZcmCameraCalibratingParams.
 * When no longer needed, destroy it with ZcmCameraCalibratingParams_destroy()
 */
ZcmCameraCalibratingParams* ZcmCameraCalibratingParams_copy(const ZcmCameraCalibratingParams* to_copy);

/**
 * Destroy an instance of ZcmCameraCalibratingParams created by ZcmCameraCalibratingParams_copy()
 */
void ZcmCameraCalibratingParams_destroy(ZcmCameraCalibratingParams* to_destroy);

/**
 * Identifies a single subscription.  This is an opaque data type.
 */
typedef struct _ZcmCameraCalibratingParams_subscription_t ZcmCameraCalibratingParams_subscription_t;

/**
 * Prototype for a callback function invoked when a message of type
 * ZcmCameraCalibratingParams is received.
 */
typedef void(*ZcmCameraCalibratingParams_handler_t)(const zcm_recv_buf_t* rbuf,
             const char* channel, const ZcmCameraCalibratingParams* msg, void* userdata);

/**
 * Publish a message of type ZcmCameraCalibratingParams using ZCM.
 *
 * @param zcm The ZCM instance to publish with.
 * @param channel The channel to publish on.
 * @param msg The message to publish.
 * @return 0 on success, <0 on error.  Success means ZCM has transferred
 * responsibility of the message data to the OS.
 */
int ZcmCameraCalibratingParams_publish(zcm_t* zcm, const char* channel, const ZcmCameraCalibratingParams* msg);

/**
 * Subscribe to messages of type ZcmCameraCalibratingParams using ZCM.
 *
 * @param zcm The ZCM instance to subscribe with.
 * @param channel The channel to subscribe to.
 * @param handler The callback function invoked by ZCM when a message is received.
 *                This function is invoked by ZCM during calls to zcm_handle() and
 *                zcm_handle_timeout().
 * @param userdata An opaque pointer passed to @p handler when it is invoked.
 * @return pointer to subscription type, NULL if failure. Must clean up
 *         dynamic memory by passing the pointer to ZcmCameraCalibratingParams_unsubscribe.
 */
ZcmCameraCalibratingParams_subscription_t* ZcmCameraCalibratingParams_subscribe(zcm_t* zcm, const char* channel, ZcmCameraCalibratingParams_handler_t handler, void* userdata);

/**
 * Removes and destroys a subscription created by ZcmCameraCalibratingParams_subscribe()
 */
int ZcmCameraCalibratingParams_unsubscribe(zcm_t* zcm, ZcmCameraCalibratingParams_subscription_t* hid);
/**
 * Encode a message of type ZcmCameraCalibratingParams into binary form.
 *
 * @param buf The output buffer.
 * @param offset Encoding starts at this byte offset into @p buf.
 * @param maxlen Maximum number of bytes to write.  This should generally
 *               be equal to ZcmCameraCalibratingParams_encoded_size().
 * @param msg The message to encode.
 * @return The number of bytes encoded, or <0 if an error occured.
 */
int ZcmCameraCalibratingParams_encode(void* buf, uint32_t offset, uint32_t maxlen, const ZcmCameraCalibratingParams* p);

/**
 * Decode a message of type ZcmCameraCalibratingParams from binary form.
 * When decoding messages containing strings or variable-length arrays, this
 * function may allocate memory.  When finished with the decoded message,
 * release allocated resources with ZcmCameraCalibratingParams_decode_cleanup().
 *
 * @param buf The buffer containing the encoded message
 * @param offset The byte offset into @p buf where the encoded message starts.
 * @param maxlen The maximum number of bytes to read while decoding.
 * @param msg Output parameter where the decoded message is stored
 * @return The number of bytes decoded, or <0 if an error occured.
 */
int ZcmCameraCalibratingParams_decode(const void* buf, uint32_t offset, uint32_t maxlen, ZcmCameraCalibratingParams* msg);

/**
 * Release resources allocated by ZcmCameraCalibratingParams_decode()
 * @return 0
 */
int ZcmCameraCalibratingParams_decode_cleanup(ZcmCameraCalibratingParams* p);

/**
 * Check how many bytes are required to encode a message of type ZcmCameraCalibratingParams
 */
uint32_t ZcmCameraCalibratingParams_encoded_size(const ZcmCameraCalibratingParams* p);
uint32_t ZcmCameraCalibratingParams_struct_size(void);
uint32_t ZcmCameraCalibratingParams_num_fields(void);
int      ZcmCameraCalibratingParams_get_field(const ZcmCameraCalibratingParams* p, uint32_t i, zcm_field_t* f);
const zcm_type_info_t* ZcmCameraCalibratingParams_get_type_info(void);

// ZCM support functions. Users should not call these
int64_t  __ZcmCameraCalibratingParams_get_hash(void);
uint64_t __ZcmCameraCalibratingParams_hash_recursive(const __zcm_hash_ptr* p);
int      __ZcmCameraCalibratingParams_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const ZcmCameraCalibratingParams* p, uint32_t elements);
int      __ZcmCameraCalibratingParams_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, ZcmCameraCalibratingParams* p, uint32_t elements);
int      __ZcmCameraCalibratingParams_decode_array_cleanup(ZcmCameraCalibratingParams* p, uint32_t elements);
uint32_t __ZcmCameraCalibratingParams_encoded_array_size(const ZcmCameraCalibratingParams* p, uint32_t elements);
uint32_t __ZcmCameraCalibratingParams_clone_array(const ZcmCameraCalibratingParams* p, ZcmCameraCalibratingParams* q, uint32_t elements);

#ifdef __cplusplus
}
#endif

#endif