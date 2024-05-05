/*

An image editing application written in C++ with a graphical user interface (GUI) includes two functions:
• OnButtonGaussianBlur and
• OnButtonMosaicDistort
each of which is called by the GUI framework in response to a user press of the corresponding button in the GUI.
class Image;
   void gaussianBlurAlgorithm(Image *img, float xSize, float ySize);
   void mosaicDistortAlgorithm(Image *img, float tileSize, float tileHeight, float tileNeatness);


class MyFrame {
   void OnButtonGaussianBlur() {
   gaussianBlurAlgorithm(img,xSize,ySize);
   }

    void OnButtonMosaicDistort() {
    mosaicDistortAlgorithm(img,tileSize,tileHeight,tileNeatness);
    }

    Image *img;
    float xSize, ySize;
    float tileSize,tileHeight,tileNeatness;
}

The current implementation is however problematic as the image processing algorithms gaussianBlurAlgorithm
and mosaicDistortAlgorithm take several seconds, blocking the GUI. It is thus desirable to move both heavy
computations in a SINGLE background thread with a lifetime equal to that of the MyFrame class.
Question 1.1 (Points 4)
Complete the following BackgroundWorker class such that:
1. it should be possible to add background operations through the BackgroundWorker::add method, which,
in turn, adds such operations to the internal queue.
2. the consumer thread, which is started on BackgroundWorker construction, consumes operations from the
queue sequentially and exits when BackgroundWorker is deleted; note that the BackgroundWorker destructor 
must wait until all pending operations are finished. Add the appropriate fields to the class if needed.

*/

// REACTOR design pattern


# ifndef BACKGROUND_WORKER
# define BACKGROUND_WORKER

# include <functional>
# include <list>
# include <thread>
# include <mutex>
# include <condition_variable>
# include <atomic>

using namespace std;

class BackgroundWorker {
    public:
        BackgroundWorker();

        ~BackgroundWorker();

        void add (function<void ()> f);


    private:
        BackgroundWorker (const BackgroundWorker&) = delete;
        BackgroundWorker operator=(const BackgroundWorker&) = delete;
        void consumer ();
        list<function<void ()>> queue;
        thread t;
        atomic<bool> quit;
        mutex m;
        condition_variable cv;

};

# endif