#include "player.h"

player::player(QObject *parent) : QObject(parent)
{
    //设置采样格式
    QAudioFormat audioFormat;
    //设置采样率
    audioFormat.setSampleRate(48000);
    //设置通道数
    audioFormat.setChannelCount(1);
    //设置采样大小，一般为8位或16位
    audioFormat.setSampleSize(16);
    //设置编码方式
    audioFormat.setCodec("audio/pcm");
    //设置字节序
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    //设置样本数据类型
    audioFormat.setSampleType(QAudioFormat::UnSignedInt);
    //音频设备信息
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultOutputDevice();
    if (!info.isFormatSupported(audioFormat)) {
        qDebug()<<"default format not supported try to use nearest";
        audioFormat = info.nearestFormat(audioFormat);
    }
    audioOutput = new QAudioOutput(audioFormat, this);
    streamOut = audioOutput->start();
    //定时器
    timer=new QTimer(this);
    connect(timer, SIGNAL(timeout()), SLOT(slotTimeout()));
    timer->start(23);
}
void player::slotTimeout()
{



    //tempBuffer.append(fileBuffer+i*1764,1764);

    if(audioOutput&&audioOutput->state()!=QAudio::StoppedState&&
            audioOutput->state()!=QAudio::SuspendedState)
    {
        int chunks = audioOutput->bytesFree()/audioOutput->periodSize();
        while (chunks)
        {
            if (tempBuffer.length() >= audioOutput->periodSize())
            {
                //写入到扬声器
                streamOut->write(tempBuffer.data(),audioOutput->periodSize());
                tempBuffer = tempBuffer.mid(audioOutput->periodSize());
            }
            else
            {
                //写入到扬声器
                streamOut->write(tempBuffer);
                tempBuffer.clear();
                break;
            }
            --chunks;
        }
    }


}
