// THIS IS AN AUTOMATICALLY GENERATED FILE.
// DO NOT MODIFY BY HAND!!
//
// Generated by zcm-gen

#include <string.h>
#ifndef ZCM_EMBEDDED
#include <stdio.h>
#endif
#include "ZcmCameraBaslerFrame.h"

static int __ZcmCameraBaslerFrame_hash_computed = 0;
static uint64_t __ZcmCameraBaslerFrame_hash;

uint64_t __ZcmCameraBaslerFrame_hash_recursive(const __zcm_hash_ptr* p)
{
    const __zcm_hash_ptr* fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __ZcmCameraBaslerFrame_get_hash)
            return 0;

    __zcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__ZcmCameraBaslerFrame_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0xc1fb59f6c4809a3cLL
         + __ZcmCameraBaslerInformation_hash_recursive(&cp)
         + __ZcmCameraBaslerImagePresentation_hash_recursive(&cp)
         + __boolean_hash_recursive(&cp)
         + __int64_t_hash_recursive(&cp)
         + __ZcmService_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __ZcmCameraBaslerFrame_get_hash(void)
{
    if (!__ZcmCameraBaslerFrame_hash_computed) {
        __ZcmCameraBaslerFrame_hash = (int64_t)__ZcmCameraBaslerFrame_hash_recursive(NULL);
        __ZcmCameraBaslerFrame_hash_computed = 1;
    }

    return __ZcmCameraBaslerFrame_hash;
}

int __ZcmCameraBaslerFrame_encode_array(void* buf, uint32_t offset, uint32_t maxlen, const ZcmCameraBaslerFrame* p, uint32_t elements)
{
    uint32_t pos = 0, element;
    int thislen;

    for (element = 0; element < elements; ++element) {

        thislen = __ZcmCameraBaslerInformation_encode_array(buf, offset + pos, maxlen - pos, &(p[element].info), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __ZcmCameraBaslerImagePresentation_encode_array(buf, offset + pos, maxlen - pos, &(p[element].image), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_encode_array(buf, offset + pos, maxlen - pos, &(p[element].synchronized), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].timestamp_ns), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __ZcmService_encode_array(buf, offset + pos, maxlen - pos, &(p[element].service), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int ZcmCameraBaslerFrame_encode(void* buf, uint32_t offset, uint32_t maxlen, const ZcmCameraBaslerFrame* p)
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = __ZcmCameraBaslerFrame_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __ZcmCameraBaslerFrame_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

uint32_t __ZcmCameraBaslerFrame_encoded_array_size(const ZcmCameraBaslerFrame* p, uint32_t elements)
{
    uint32_t size = 0, element;
    for (element = 0; element < elements; ++element) {

        size += __ZcmCameraBaslerInformation_encoded_array_size(&(p[element].info), 1);

        size += __ZcmCameraBaslerImagePresentation_encoded_array_size(&(p[element].image), 1);

        size += __boolean_encoded_array_size(&(p[element].synchronized), 1);

        size += __int64_t_encoded_array_size(&(p[element].timestamp_ns), 1);

        size += __ZcmService_encoded_array_size(&(p[element].service), 1);

    }
    return size;
}

uint32_t ZcmCameraBaslerFrame_encoded_size(const ZcmCameraBaslerFrame* p)
{
    return 8 + __ZcmCameraBaslerFrame_encoded_array_size(p, 1);
}

uint32_t ZcmCameraBaslerFrame_struct_size(void)
{
    return sizeof(ZcmCameraBaslerFrame);
}

uint32_t ZcmCameraBaslerFrame_num_fields(void)
{
    return 5;
}

int ZcmCameraBaslerFrame_get_field(const ZcmCameraBaslerFrame* p, uint32_t i, zcm_field_t* f)
{
    if (i >= ZcmCameraBaslerFrame_num_fields())
        return 1;
    
    switch (i) {
    
        case 0: {
            /* ZcmCameraBaslerInformation */
            f->name = "info";
            f->type = ZCM_FIELD_USER_TYPE;
            f->typestr = "ZcmCameraBaslerInformation";
            f->num_dim = 0;
            f->data = (void*) &p->info;
            return 0;
        }
        
        case 1: {
            /* ZcmCameraBaslerImagePresentation */
            f->name = "image";
            f->type = ZCM_FIELD_USER_TYPE;
            f->typestr = "ZcmCameraBaslerImagePresentation";
            f->num_dim = 0;
            f->data = (void*) &p->image;
            return 0;
        }
        
        case 2: {
            f->name = "synchronized";
            f->type = ZCM_FIELD_BOOLEAN;
            f->typestr = "boolean";
            f->num_dim = 0;
            f->data = (void*) &p->synchronized;
            return 0;
        }
        
        case 3: {
            f->name = "timestamp_ns";
            f->type = ZCM_FIELD_INT64_T;
            f->typestr = "int64_t";
            f->num_dim = 0;
            f->data = (void*) &p->timestamp_ns;
            return 0;
        }
        
        case 4: {
            /* ZcmService */
            f->name = "service";
            f->type = ZCM_FIELD_USER_TYPE;
            f->typestr = "ZcmService";
            f->num_dim = 0;
            f->data = (void*) &p->service;
            return 0;
        }
        
        default:
            return 1;
    }
}

const zcm_type_info_t* ZcmCameraBaslerFrame_get_type_info(void)
{
    static int init = 0;
    static zcm_type_info_t typeinfo;
    if (!init) {
        typeinfo.encode         = (zcm_encode_t) ZcmCameraBaslerFrame_encode;
        typeinfo.decode         = (zcm_decode_t) ZcmCameraBaslerFrame_decode;
        typeinfo.decode_cleanup = (zcm_decode_cleanup_t) ZcmCameraBaslerFrame_decode_cleanup;
        typeinfo.encoded_size   = (zcm_encoded_size_t) ZcmCameraBaslerFrame_encoded_size;
        typeinfo.struct_size    = (zcm_struct_size_t)  ZcmCameraBaslerFrame_struct_size;
        typeinfo.num_fields     = (zcm_num_fields_t) ZcmCameraBaslerFrame_num_fields;
        typeinfo.get_field      = (zcm_get_field_t) ZcmCameraBaslerFrame_get_field;
        typeinfo.get_hash       = (zcm_get_hash_t) __ZcmCameraBaslerFrame_get_hash;
    }
    
    return &typeinfo;
}
int __ZcmCameraBaslerFrame_decode_array(const void* buf, uint32_t offset, uint32_t maxlen, ZcmCameraBaslerFrame* p, uint32_t elements)
{
    uint32_t pos = 0, element;
    int thislen;

    for (element = 0; element < elements; ++element) {

        thislen = __ZcmCameraBaslerInformation_decode_array(buf, offset + pos, maxlen - pos, &(p[element].info), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __ZcmCameraBaslerImagePresentation_decode_array(buf, offset + pos, maxlen - pos, &(p[element].image), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __boolean_decode_array(buf, offset + pos, maxlen - pos, &(p[element].synchronized), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].timestamp_ns), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __ZcmService_decode_array(buf, offset + pos, maxlen - pos, &(p[element].service), 1);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __ZcmCameraBaslerFrame_decode_array_cleanup(ZcmCameraBaslerFrame* p, uint32_t elements)
{
    uint32_t element;
    for (element = 0; element < elements; ++element) {

        __ZcmCameraBaslerInformation_decode_array_cleanup(&(p[element].info), 1);

        __ZcmCameraBaslerImagePresentation_decode_array_cleanup(&(p[element].image), 1);

        __boolean_decode_array_cleanup(&(p[element].synchronized), 1);

        __int64_t_decode_array_cleanup(&(p[element].timestamp_ns), 1);

        __ZcmService_decode_array_cleanup(&(p[element].service), 1);

    }
    return 0;
}

int ZcmCameraBaslerFrame_decode(const void* buf, uint32_t offset, uint32_t maxlen, ZcmCameraBaslerFrame* p)
{
    uint32_t pos = 0;
    int thislen;
    int64_t hash = __ZcmCameraBaslerFrame_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __ZcmCameraBaslerFrame_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int ZcmCameraBaslerFrame_decode_cleanup(ZcmCameraBaslerFrame* p)
{
    return __ZcmCameraBaslerFrame_decode_array_cleanup(p, 1);
}

uint32_t __ZcmCameraBaslerFrame_clone_array(const ZcmCameraBaslerFrame* p, ZcmCameraBaslerFrame* q, uint32_t elements)
{
    uint32_t n = 0, element;
    for (element = 0; element < elements; ++element) {

        n += __ZcmCameraBaslerInformation_clone_array(&(p[element].info), &(q[element].info), 1);

        n += __ZcmCameraBaslerImagePresentation_clone_array(&(p[element].image), &(q[element].image), 1);

        n += __boolean_clone_array(&(p[element].synchronized), &(q[element].synchronized), 1);

        n += __int64_t_clone_array(&(p[element].timestamp_ns), &(q[element].timestamp_ns), 1);

        n += __ZcmService_clone_array(&(p[element].service), &(q[element].service), 1);

    }
    return n;
}

ZcmCameraBaslerFrame* ZcmCameraBaslerFrame_copy(const ZcmCameraBaslerFrame* p)
{
    ZcmCameraBaslerFrame* q = (ZcmCameraBaslerFrame*) malloc(sizeof(ZcmCameraBaslerFrame));
    __ZcmCameraBaslerFrame_clone_array(p, q, 1);
    return q;
}

void ZcmCameraBaslerFrame_destroy(ZcmCameraBaslerFrame* p)
{
    __ZcmCameraBaslerFrame_decode_array_cleanup(p, 1);
    free(p);
}

int ZcmCameraBaslerFrame_publish(zcm_t* zcm, const char* channel, const ZcmCameraBaslerFrame* p)
{
      uint32_t max_data_size = ZcmCameraBaslerFrame_encoded_size (p);
      uint8_t* buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = ZcmCameraBaslerFrame_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = zcm_publish (zcm, channel, buf, (uint32_t)data_size);
      free (buf);
      return status;
}

struct _ZcmCameraBaslerFrame_subscription_t {
    ZcmCameraBaslerFrame_handler_t user_handler;
    void* userdata;
    zcm_sub_t* z_sub;
};
static
void ZcmCameraBaslerFrame_handler_stub (const zcm_recv_buf_t* rbuf,
                            const char* channel, void* userdata)
{
    int status;
    ZcmCameraBaslerFrame p;
    memset(&p, 0, sizeof(ZcmCameraBaslerFrame));
    status = ZcmCameraBaslerFrame_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        #ifndef ZCM_EMBEDDED
        fprintf (stderr, "error %d decoding ZcmCameraBaslerFrame!!!\n", status);
        #endif
        return;
    }

    ZcmCameraBaslerFrame_subscription_t* h = (ZcmCameraBaslerFrame_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    ZcmCameraBaslerFrame_decode_cleanup (&p);
}

ZcmCameraBaslerFrame_subscription_t* ZcmCameraBaslerFrame_subscribe (zcm_t* zcm,
                    const char* channel,
                    ZcmCameraBaslerFrame_handler_t f, void* userdata)
{
    ZcmCameraBaslerFrame_subscription_t* n = (ZcmCameraBaslerFrame_subscription_t*)
                       malloc(sizeof(ZcmCameraBaslerFrame_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->z_sub = zcm_subscribe (zcm, channel,
                              ZcmCameraBaslerFrame_handler_stub, n);
    if (n->z_sub == NULL) {
        #ifndef ZCM_EMBEDDED
        fprintf (stderr,"couldn't reg ZcmCameraBaslerFrame ZCM handler!\n");
        #endif
        free (n);
        return NULL;
    }
    return n;
}

int ZcmCameraBaslerFrame_unsubscribe(zcm_t* zcm, ZcmCameraBaslerFrame_subscription_t* hid)
{
    int status = zcm_unsubscribe (zcm, hid->z_sub);
    if (0 != status) {
        #ifndef ZCM_EMBEDDED
        fprintf(stderr,
           "couldn't unsubscribe ZcmCameraBaslerFrame_handler %p!\n", hid);
        #endif
        return -1;
    }
    free (hid);
    return 0;
}

