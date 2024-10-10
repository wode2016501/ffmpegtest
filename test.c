
#include "libavcodec/avcodec.h" 
#include "libavfilter/avfilter.h"
#include "libavformat/avformat.h"
#include "libavutil/avutil.h"
#include "libavutil/ffversion.h"
#include "libswresample/swresample.h"

int main(){
	char *filePath="/sdcard/test.mp4"; 
	AVFormatContext *fmtCtx=NULL;
	AVCodecParameters *avCodecPara=NULL;
	int videoStreamIndex =-1; 
	int ret=0; 
	if ((ret=avformat_open_input(&fmtCtx, filePath, NULL, NULL)) != 0) {                        printf("打开输入视频错误 video file %s\n",filePath);                                                                                                               }
	if ((ret=avformat_find_stream_info(fmtCtx, NULL)) < 0) {                                    printf("cannot retrive video info\n");        							      }
	for (unsigned int i = 0; i < fmtCtx->nb_streams; i++) {                                     if (fmtCtx->streams[ i ]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {                     videoStreamIndex = i;
		break;//找到视频流就退出   
	}                                                                                   }                                                                                                                                                                               //如果videoStream为-1 说明没有找到视频流 
	if (videoStreamIndex == -1) {
		printf("cannot find video stream\n");
		return 0; 
	}
	av_dump_format(fmtCtx, 0, filePath, 0);
	avCodecPara = fmtCtx->streams[ videoStreamIndex ]->codecpar;
	AVCodec *codec=NULL;
	codec=avcodec_find_decoder_by_name("h264_mediacodec");
	AVCodecContext *codecCtx=NULL;
	codecCtx = avcodec_alloc_context3(codec);	
	int p=0;
	avcodec_parameters_to_context(codecCtx, avCodecPara);
	if ((ret=avcodec_open2(codecCtx, codec,NULL)) < 0) // 具体采用什么解码器ffmpeg经过封装 我们无须知道 
		printf("打开错误 %d\n",ret);


}
