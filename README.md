# kurento-module-dtmfdetect
DTMF detection filter for Kurento to detect DTMF tones in the audio signal

Add this filter in the (audio) path and it will fire the DtmfDetected event when a DTMF tone is detected

This filter is based on the [GStreamer dtmfdetect filter](https://gstreamer.freedesktop.org/data/doc/gstreamer/head/gst-plugins-bad-plugins/html/gst-plugins-bad-plugins-dtmfdetect.html)

## How to use

1. Compile the module. See instructions below
2. Download the nodejs module and/or add it to your package.json
3. (optional) Download and run the sample project


### Compiling

Install the dependencies
```
sudo apt-get install kurento-media-server-6.0-dev
```

Clone this repository
```
git clone https://github.com/tvandergeer/kurento-module-dtmfdetect.git
```

Build it
```
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/
make -j4
```
(optional) If you want to build the node module as well, use the folling command
```
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/ -DGENERATE_JS_CLIENT_PROJECT=TRUE
```
Install the module
```
sudo make -j4 install
```
Restart kurento-media-server
```
sudo service kurento-media-server-6.0 restart
```


For more Kurento build instructions see [here](https://github.com/Kurento/kurento-media-server)



