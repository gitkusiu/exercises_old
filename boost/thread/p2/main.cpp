#include <boost/thread/thread.hpp>
#include <iostream>
#include <cstdio>
////using namespace boost;
////using namespace boost::this_thread;
using namespace std;

class AnimationClass
{
private:
    boost::thread* m_thread; // The thread runs this object
    int m_frame; // The current frame number
 
// Variable that indicates to stop and the mutex to
// synchronise "must stop" on (mutex explained later)
    bool m_mustStop;
    boost::mutex m_mustStopMutex;
 
public:
// Default constructor
    AnimationClass()
    {
        m_thread=NULL;
        m_mustStop=false;
        m_frame=0;
    }
 
// Destructor
    ~AnimationClass()
    {
        if (m_thread!=NULL) delete m_thread;
    }
 
// Start the threa
    void Start()
    {
        // Create thread and start it with myself as argument.
        // Pass myself as reference since I don't want a copy
        m_thread=new boost::thread(boost::ref(*this));
    }
 
// Stop the thread
    void Stop()
    {
    // Signal the thread to stop (thread-safe)
//        m_mustStopMutex.lock();
        m_mustStop=true;
//        m_mustStopMutex.unlock();
 
    // Wait for the thread to finish.
        if (m_thread!=NULL) m_thread->join();
    }
 
// Display next frame of the animation
    void DisplayNextFrame()
    {
        // Simulate next frame
        cout<<"Press <RETURN> to stop. Frame: "<<m_frame++<<endl;
    }
 
    // Thread function
    void operator () ()
    {
        bool mustStop;
 
        do
        {
            // Display the next animation frame
            DisplayNextFrame();
 
            // Sleep for 40ms (25 frames/second).
            boost::this_thread::sleep(boost::posix_time::millisec(40));
 
            // Get the "must stop" state (thread-safe)
            m_mustStopMutex.lock();
            mustStop=m_mustStop;
            m_mustStopMutex.unlock();
        }
        while (mustStop==false);
    }
};




int main()
{
    // Create and start the animation class
    AnimationClass ac;
    ac.Start();
 
// Wait for the user to press return
    getchar();
 
// Stop the animation class
    cout << "Animation stopping..." << endl;
    ac.Stop();
    cout << "Animation stopped." << endl;
 
    return 0;
}



//int main()
//{
//  boost::thread t;
//  t.join();
//}
