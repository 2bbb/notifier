#include "ofMain.h"

#include "notifier.hpp"

class ofApp : public ofBaseApp {
    bbb::notifier<int> x;
    bbb::notifier<std::string> str{"abc"};
public:
    void setup() {
        std::function<void()> f;
        x.value_will_change([](int x) { ofLogNotice("x") << "from " << x; });
        x.value_did_change([](int x) { ofLogNotice("x") << "to " << x; });
        str.value_will_change([](const std::string &str) { ofLogNotice("str") << "from " << str; });
        str.value_did_change([](const std::string &str) { ofLogNotice("str") << "to " << str; });
        x = 4;
    }
    void update() {
        
    }
    void draw() {
        
    }
    
    void exit() {}
    
    void keyPressed(int key) {
        if(key == ' ') {
            x++;
        } else if(std::isprint(key)) {
            str += static_cast<char>(key);
        } else if(key == OF_KEY_BACKSPACE) {
            str = str.substr(0, str.size() - 1);
        } else if(key == '\t') {
            str[0]++;
        }
    }
    void keyReleased(int key) {}
    void mouseMoved(int x, int y) {}
    void mouseDragged(int x, int y, int button) {}
    void mousePressed(int x, int y, int button) {}
    void mouseReleased(int x, int y, int button) {}
    void mouseEntered(int x, int y) {}
    void mouseExited(int x, int y) {}
    void windowResized(int w, int h) {}
    void dragEvent(ofDragInfo dragInfo) {}
    void gotMessage(ofMessage msg) {}
};

int main() {
    ofSetupOpenGL(1280, 720, OF_WINDOW);
    ofRunApp(new ofApp);
}
