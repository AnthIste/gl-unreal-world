#ifndef INC_UWLMAN_INPUT_MANAGER_H
#define INC_UWLMAN_INPUT_MANAGER_H

namespace uwlman {

class InputManager {
public:
    InputManager();

    virtual ~InputManager() { }

    virtual void processInput();

    // TODO: transparent key API
    virtual void acceptKeyDown(int key, int scancode, int mods);

    // TODO: transparent key API
    virtual void acceptKeyUp(int key, int scancode, int mods);

    // TODO: transparent mouse API
    virtual void acceptMouseDown(int button, int mods);

    // TODO: transparent mouse API
    virtual void acceptMouseUp(int button, int mods);

    // TODO: transparent mouse API
    virtual bool isKeyDown(int key);

private:
    bool keys[512];
    bool mouseButtons[16];
    int modifiers;

};

};

#endif
