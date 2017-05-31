#include "gstdtmfdetect.h"

#include <gst/gst.h>
#include <gst/audio/audio.h>
#include <gst/audio/gstaudiofilter.h>
#include <glib/gstdio.h>
#include <opencv2/opencv.hpp>
#include <cv.h>
#include <memory>

GST_DEBUG_CATEGORY_STATIC (gst_dtmf_detect_debug_category);
#define GST_CAT_DEFAULT gst_dtmf_detect_debug_category
#define PLUGIN_NAME "dtmfdetect"

#define GST_DTMF_DETECT_GET_PRIVATE(obj) (    \
    G_TYPE_INSTANCE_GET_PRIVATE (               \
        (obj),                                  \
        GST_TYPE_DTMF_DETECT,                 \
        GstDtmfDetectPrivate                  \
                                )               \
                                           )

/* pad templates */

#define AUDIO_SRC_CAPS \
  GST_AUDIO_CAPS_MAKE("{ S16LE }")

#define AUDIO_SINK_CAPS \
  GST_AUDIO_CAPS_MAKE("{ S16LE }")

/* class initialization */

G_DEFINE_TYPE_WITH_CODE (GstDtmfDetect, gst_dtmf_detect,
                         GST_TYPE_AUDIO_FILTER,
                         GST_DEBUG_CATEGORY_INIT (gst_dtmf_detect_debug_category,
                             PLUGIN_NAME, 0,
                             "debug category for dtmf_detect element") );

static void
gst_dtmf_detect_finalize (GObject *object)
{
}

static void
gst_dtmf_detect_init (GstDtmfDetect *
                        dtmf_detect)
{
}

static void
gst_dtmf_detect_class_init (GstDtmfDetectClass *klass)
{
  GObjectClass *gobject_class = G_OBJECT_CLASS (klass);

  GST_DEBUG_CATEGORY_INIT (GST_CAT_DEFAULT, PLUGIN_NAME, 0, PLUGIN_NAME);

  gst_element_class_add_pad_template (GST_ELEMENT_CLASS (klass),
                                      gst_pad_template_new ("src", GST_PAD_SRC,
                                          GST_PAD_ALWAYS,
                                          gst_caps_from_string (AUDIO_SRC_CAPS) ) );
  gst_element_class_add_pad_template (GST_ELEMENT_CLASS (klass),
                                      gst_pad_template_new ("sink", GST_PAD_SINK,
                                          GST_PAD_ALWAYS,
                                          gst_caps_from_string (AUDIO_SINK_CAPS) ) );

  gst_element_class_set_static_metadata (GST_ELEMENT_CLASS (klass),
                                      "element definition", "Audio/Filter",
                                      "Filter doc",
                                      "Developer");

  gobject_class->finalize = gst_dtmf_detect_finalize;

}

gboolean
gst_dtmf_detect_plugin_init (GstPlugin *plugin)
{
  return gst_element_register (plugin, PLUGIN_NAME, GST_RANK_NONE,
                               GST_TYPE_DTMF_DETECT);
}
