#include "renderer.h"
#include "rendererInterface.h"
#include "inputInterface.h"

struct GameState
{
  RendererInterface* rendererInterface;
  InputInterface* inputInterface;
};
