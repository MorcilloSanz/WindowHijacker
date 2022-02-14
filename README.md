# WindowHijacker
Hijack visible windows device context in order to draw an image in every visible window

## Reading image process

* Image as a buffer:

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/imageBuffer.png)

In order to get this buffer, I'm using stb_image.h

* Image as a tensor:

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/imageTensor.png)

* Get pixel function

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/pfun.png)

* Get colors of a pixel

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/rfun.png)

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/gfun.png)

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/bfun.png)

![alt text](https://github.com/MorcilloSanz/WindowHijacker/blob/main/img/afun.png)

being r, g, b, a the position of the colors red, green, blue and alpha in the **buffer B** of the pixel in the position (x,y) in the **tensor I**

## Drawing image in every window
In order to center the image in the window:

**x = (W - n) / 2**
**y = (H - m) / 2**

where W, H are the width and height of the current window and n, m are the width and height of the image.

```c
  for(Window& window : windows) {
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j < m; i ++) {
        int p = i + j * n;
        int r = 4 * p;
        int g = r + 1;
        int b = g + 1;
        int a = b + 1;
        window.setPixel(x + i, y + j, Color(buffer[r], buffer[g], buffer[b], buffer[a]));
      }
    }
  }
`
## Disclaimer

I am not responsible for any misuse that may be given to this code. It is shared for ethical purposes only
