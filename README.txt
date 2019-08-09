The color of the window is set in the build_swapchain_cmds
function, by the VkClearValue. That is where you 
can set the red, green, and blue values of the screen color

In this tutorial, we use Vulkan to draw something to the screen.
We will use Vulkan to set the color of the window. To do this,
we have to go through a long series of steps. Fair warning,
this will be the hardest tutorial. If you understand this tutorial,
then you will be able to understand all the rest.

The best thing to do for this tutorial, is to read all the comments,
starting in Main.cpp, then read the comments in Demo::Demo,
then read the comments in Demo::Prepare, and then the 
comments in each of the functions insdie Demo::Prepare,
then read the comments in Demo::Draw, then read the comments
in the Demo destructor Demo::~Demo

Functions in the last tutorial, like prepare_instance() will be 
changed significantly in this tutorial, so please remember to 
thoroughly read the comments. Skipping around will only
make the learning process more difficult

Everyone here should know how to graph a slope:
y = mx + b
'm' is the slope of the graph,
and 'b' is the y-intercept.

Here is how I like to look at Vulkan. As you'll see in this
tutorial, it takes a HUGE TON of code to get started,
but after this tutorial, it does not take a lot of code to 
add more things. So, I like to think of vulkan as the
graph equation
	y = x + 1000
Because it takes a lot to get started, but once
you've finally drawn the 3D cube at the end of this
series, it just gets easeir and easier from that point on