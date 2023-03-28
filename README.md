# dtmf_generator
Simple DTMF-generator based on Mediastreamer2.
![image](https://user-images.githubusercontent.com/1526432/228306570-0fa9479d-81cc-4a31-bdaa-4f498778fe15.png)

This program is example of simple audio signal generator for my article on Medium:<br>
[What’s Mediastreamer2. Examples of Filters Using](https://medium.com/gitconnected/chapter-3-examples-of-using-filters-612f2121301)

Russian version in book:<br>["Изучаем Mediastreamer2"](https://drive.google.com/file/d/1OEY1VwcelQXMg3oF0HFuolZ11dlFv1lO/view?usp=sharing) 

## How to compile

```
$ gcc mstest2.c -o mstest2 `pkg-config Mediastreamer2 --libs --cflags`
```
## How to run
```
$ ./mstest2
```
