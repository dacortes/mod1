#include <MlxWindow.hpp>
#include <Scene2D.hpp>
#include <utils.tpp>

using Scene = std::unique_ptr<AScene>;

int main(void)
{
    MlxWindow app("foo", 500, 500);
    Scene2D *fooScene = new Scene2D(0, 0, 0);
    Scene foo(fooScene);
    app.addScene("foo", std::move(foo));
	app.switchToScene("foo");
	app.loop();
    return (EXIT_SUCCESS);
}