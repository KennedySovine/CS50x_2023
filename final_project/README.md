# TWITCH SPEAK
#### Video Demo: https://youtu.be/TZ1xvRJXf3E
#### Description:

This chrome extention turns all webpages into Twitch speak. This integrates words such as pog, VOD, sagde, and emotes.

This extention came about due to Harvard's CS50 program. This is my final project for introduction to Computer Science.

I originally wrote this extention a little over a year ago now. I took CS50 back in my last year of high school during my independent study.

Originally, the chrome extention had been planned to be a hydrate reminder type of extention, where everytime you hydrate, a dog is happy. Unforutnately, Chrome is mean and does not allow what I planned to actually happen unless I used a complicated storage sync thing that they require. Since I value my sanity, I decided to change the project into a simplier chrome extention that modifies the webpage. Hopefully one day I can have the expertience to be able to set up my original idea.

## Steps to open:
1. Go to chrome://extentions
![Image of chrome extentions](https://github.com/KennedySovine/CS50x_2023/blob/main/final_project/Images/Step_1.png)
2. Turn on developer mode
![Developer mode on](/Images/Step_2.png)
3. and then unload the extention and make sure it is turned on.
![Extention is turned on](/Images/Step_3.png)

Manifest.json identifies the extention and allows for the extention to alter the page. This is required because without it, the extention wouldn't be able to alter the page at all and would be useless.

Popup.js is the scirpt that replaces the words on the webpage to include plurals and capitals. To do this, there are many media queries to select the words no matter where they appear on the page. It accesses many different HTML types to do this.

Though this extention is rather small, it's purpose is purely for comedic sake. It isn't meant to revolutionize the way people use their computers nor how they go about the internet. It is meant to be a fun 'gag' extention that people can have fun with.

The inspiration for the extention came from my own use on the internet. I frequent the website 'Twitch' (the namesake for the extention), where people can go live doig whatever, typically playing games, and people can watch. Through this, many people have formulated communities on the website. Along with them came new slang that is integrated in the extention.

- 'Pog': "play of the game" or can mean "awesome". (Variations: Poggers)
- 'Vod': short for "video". Whenever you stream on twitch, your livestream can be saved as a video or 'vod' that can be left up for a time or exported to other sites like Youtube.
- 'Emote': a small image used in the chat that can denote a reaction or feeling to something the streamer had said or done.
- 'Cap': to say something is the truth or a lie. ("Youre capping" -> lying) ("No cap" -> the truth). The meaning of cap can be changed and sometimes hard to decern.
- 'Bits': the virtual currency on Twitch. Users pay real money for bits that can then be sent to their favorite streamers.
- 'Prime': the Amazon subscription service. If connected to a twitch account, it can allow the user 1 free subscription to a streamer who has them enabled.
- 'Sadge': an internet variation of sad.
- 'Gamers': a way some streamers describe their chat. "Hey, Gamers" is an example.

There isn't much to document about the extention itself because it is rather simple in nature. Document query selectors are simple and being able to change the contents of a webpage is something many have done through 'Inspect Element' when they were playign around the internet as children. Despite its simplicity, I am still rather proiud of my work and hope that everyone who installs the extention enjoys it.
