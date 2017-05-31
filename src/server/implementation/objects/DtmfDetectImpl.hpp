/* Autogenerated with kurento-module-creator */

#ifndef __DTMF_DETECT_IMPL_HPP__
#define __DTMF_DETECT_IMPL_HPP__

#include "FilterImpl.hpp"
#include "DtmfDetect.hpp"
#include <EventHandler.hpp>
#include <boost/property_tree/ptree.hpp>

namespace kurento
{
namespace module
{
namespace dtmfdetect
{
class DtmfDetectImpl;
} /* dtmfdetect */
} /* module */
} /* kurento */

namespace kurento
{
void Serialize (std::shared_ptr<kurento::module::dtmfdetect::DtmfDetectImpl> &object, JsonSerializer &serializer);
} /* kurento */

namespace kurento
{
class MediaPipelineImpl;
} /* kurento */

namespace kurento
{
namespace module
{
namespace dtmfdetect
{

class DtmfDetectImpl : public FilterImpl, public virtual DtmfDetect
{

public:

  DtmfDetectImpl (const boost::property_tree::ptree &config, std::shared_ptr<MediaPipeline> mediaPipeline);

  virtual ~DtmfDetectImpl ();

  /* Next methods are automatically implemented by code generator */
  virtual bool connect (const std::string &eventType, std::shared_ptr<EventHandler> handler);

  sigc::signal<void, DtmfDetected> signalDtmfDetected;
  virtual void invoke (std::shared_ptr<MediaObjectImpl> obj,
                       const std::string &methodName, const Json::Value &params,
                       Json::Value &response);

  virtual void Serialize (JsonSerializer &serializer);

protected:
  virtual void postConstructor ();

private:
  
  GstElement *dtmfdetect;
  gulong bus_handler_id;

  void busMessage (GstMessage *message);

  void dtmfDetected (std::string &value);

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;

};

} /* dtmfdetect */
} /* module */
} /* kurento */

#endif /*  __DTMF_DETECT_IMPL_HPP__ */
