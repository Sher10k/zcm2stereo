#include <utility>
#include <vector>
#include <iostream>
#include <zcm/zcm-cpp.hpp>
#include <set>
#include <iterator>
#include <opencv2/core.hpp>        // Basic OpenCV structures (cv::Mat)
#include <opencv2//highgui.hpp>  // Video write

#include "ZcmCameraBaslerJpegFrame.hpp"

using namespace std;
using namespace cv;
using namespace zcm;

class stereoParser {
    
private:
    cv::Mat img_;
    zcm::LogFile *zcm_log_;
    std::string output_folder_;
//    std::string filename;
    int param_;
    bool list_;
    
public:
    stereoParser( const std::string & input_filename, std::string output_folder, int param, bool list )
        : output_folder_{std::move(output_folder)}, param_{std::move(param)}, list_{std::move(list)}
    {
        zcm_log_ = new zcm::LogFile(input_filename, "r");
        if ( !zcm_log_->good() )
        {
            std::cout << "Bad zcm log: " << input_filename << std::endl;
            exit(0);
        }
        cout << "Input zcm file: " << input_filename << endl;
        cout << "Output stereo folder: " << output_folder_ << endl;
//        size_t pos = input_filename.find_last_of('/');
//        filename = input_filename.substr( pos + 1, input_filename.length() - pos );
//        cout << "Output file name: " << filename << endl;
        cout << "N frame : " << param_ << endl;
    }
    
    void Run()
    {
        set < string > zcm_list;
        Mat img[2];                 // stereo image 
        long tts[2];                // temp time stamp
        tts[0] = 0;
        tts[1] = 0;
        int numframe = 0;
        unsigned long countSframe = 0;
        cout << "Time: " << endl;
        while (1)
        {
            const zcm::LogEvent* event = zcm_log_->readNextEvent();
            if (!event)
                break;
            ZcmCameraBaslerJpegFrame zcm_msg;
            
            if ( event->channel == "FLZcmCameraBaslerJpegFrame" )
            {
                tts[0] = zcm_msg.service.u_timestamp;
                //cout << "L " << tts[0] << endl;
                zcm_msg.decode( event->data, 0, static_cast< unsigned >( event->datalen ) );
                img[0] = imdecode( zcm_msg.jpeg, IMREAD_COLOR );
            }
            else if ( event->channel == "FRZcmCameraBaslerJpegFrame" )
            {
                tts[1] = zcm_msg.service.u_timestamp;
                //cout << "R " << tts[1] << endl;
                zcm_msg.decode( event->data, 0, static_cast< unsigned >( event->datalen ) );
                img[1] = imdecode( zcm_msg.jpeg, IMREAD_COLOR);
            }
            
            if ( (tts[0] == tts[1]) && (tts[0] != 0) && (tts[1] != 0) )
            {
                numframe++;
                if ( numframe == param_ )
                {
                    countSframe++;
                    cout << " - Num frame: " << countSframe << endl;
                    cout << "Time stamp L: " << tts[0] << endl;
                    imwrite( output_folder_ + "FLZcmCameraBaslerJpegFrame" + to_string( tts[0] ) + ".png", img[0] );
                    cout << "Time stamp R: " << tts[1] << endl;
                    imwrite( output_folder_ + "FRZcmCameraBaslerJpegFrame" + to_string( tts[1] ) + ".png", img[1] );
                    numframe = 0;
                }
            }
            zcm_list.insert( event->channel );
        }
        std::cout << "zcm_list: " << std::endl;
        for(auto i : zcm_list)
            std::cout << "\t" << i << std::endl;

        if ( !list_ ) std::cout << "Finished writing" << std::endl;
    }
};
