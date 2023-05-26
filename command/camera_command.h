#ifndef CAMERA_COMMAND_H
#define CAMERA_COMMAND_H

#include "base_command.h"
#include <stdlib.h>

class CameraCommand : public Command
{
protected:
std::size_t id;
};

class CameraNewCommand : public CameraCommand
{

};

#endif
