#include <VulkanWin.hpp>
#include <utils.tpp>

int main(void)
{
    // try
    // {
        VulkanWin app("mod1", "foo", WIDTH, HEIGHT);

        app.run();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    //     return (EXIT_FAILURE);
    // }
    
    return (EXIT_SUCCESS);
}