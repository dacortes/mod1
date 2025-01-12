#include <MlxWindow.hpp>
#include <Scene2D.hpp>
#include <utils.tpp>

using Scene = std::unique_ptr<AScene>;

int main(void)
{
    try
    {
      MlxWindow app("foo", 500, 500);
      Scene2D *fooScene = new Scene2D(0, 0, 20, 20, 0xFFFFFFAA);
      Scene foo(fooScene);
      app.addScene("foo", std::move(foo));
      app.switchToScene("foo");
      app.loop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    return (EXIT_SUCCESS);
}