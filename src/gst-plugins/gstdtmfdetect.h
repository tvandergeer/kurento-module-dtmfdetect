#ifndef _GST_DTMF_DETECT_H_
#define _GST_DTMF_DETECT_H_

#include <gst/audio/gstaudiofilter.h>

G_BEGIN_DECLS
#define GST_TYPE_DTMF_DETECT   (gst_dtmf_detect_get_type())
#define GST_DTMF_DETECT(obj)   (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_DTMF_DETECT,GstDtmfDetect))
#define GST_DTMF_DETECT_CLASS(klass)   (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_DTMF_DETECT,GstDtmfDetectClass))
#define GST_IS_DTMF_DETECT(obj)   (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_DTMF_DETECT))
#define GST_IS_DTMF_DETECT_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_DTMF_DETECT))
typedef struct _GstDtmfDetect GstDtmfDetect;
typedef struct _GstDtmfDetectClass GstDtmfDetectClass;
typedef struct _GstDtmfDetectPrivate GstDtmfDetectPrivate;

struct _GstDtmfDetect
{
  GstAudioFilter base;
  GstDtmfDetectPrivate *priv;
};

struct _GstDtmfDetectClass
{
  GstAudioFilterClass base_dtmf_detect_class;
};

GType gst_dtmf_detect_get_type (void);

gboolean gst_dtmf_detect_plugin_init (GstPlugin * plugin);

G_END_DECLS
#endif /* _GST_DTMF_DETECT_H_ */
