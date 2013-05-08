# Doodle Dive

My game is inspired by the game Doodle Jump by made by Lima Sky.  Doodle jump is a game where yor character continues to jump up platforms, and the higher the character jumps, the more points accumulate.  In this ascent, you have to find platorms to land on.  In addition, you have to avoid mosters and black warp holes that will end the game.  The gameplay  utlizes the gyroscope startphones, so direction of the doodle character jump is controlled by the angle in which the user holds the phone.  

Doodle Dive is the reverse narrative.  In Doodle Dive, the Doodle character will be falling!  The Doodle character will fall through the sky.  There will be platorms to bounce of and monsters to avoid!  

![alt text] (http://a221.phobos.apple.com/us/r1000/061/Purple2/v4/cc/af/a0/ccafa0fb-d14e-38db-cab4-4ed254f8a0eb/mzl.mdotkunf.320x480-75.jpg "Doodle Jump by Lima Sky")

# Implementation
## Things In the Game 
  1. Platforms: Platforms to bounce off up will consistently be moving upwards to make it appear as if the Doodle character is falling.  These platforms will be ***safe to land on** and stationary (but technically moving upwards).  Depending on what I decide, either my character will stop on said platform or my character will automatically bounce up from the platform (similar to the doodle jump game). These will probably be blue.  
  2. ~~Super Platforms~~
  3. Angry Platforms: This platorms are bad.  They will hurt you because they have spikes on them and this will give you damage.  Similar to the regular platforms they will move upwards to make the illusion of the Doodle character moving downwards.  They will be smaller than regular platorms but they will grow to the left. They will look like a cheese grater.  You will slow down when you move through them, as if you were being grated like a piece of cheese. 
  4. Halos: If you fall through these rings, you will get bonus health.  These rings are an homage to the sky rings that can be found in _Super Mario 64_.  This rings will be orange/yellow, pretty thin because they are hard to find. 
  5. Monsters: If you crash into a monster, you most liekly will die.  They do lots of damges  **Game over**. (Game can also be over if you get enough damage from the Angry Platforms) These monster will look like monsters.  **ALSO** If you stop on a platform, the monsters will start moving towards you.  As soon as you get off of the platform they will magicaly go back to their original position.  They don't like it when you are on their platform. 
  6. FIREBALLS:  you can only use one at a time so that you can spam.  But you can shoot it using your spacebar.  If you hit a monster, you get health and bounus points. **NEW** after you shoot your fireball the the spacebar, you can activate tracking using the "g" key.  It will track a monster on the screen an hopefully hit it, although it is not guarenteed because the tracking moves slowly. 
  7. THE DUDE.  He is your character that falls.

## Game Play
  * The fall will be controlled by mouse clicks .  If you click near the doodledude, he won't move as fast.  But if you click near bottom of screen, he'll move faster. 
  * The faster you fall, you can gain more points.  So it is sometime good to avoid platforms. Sometimes you want a platfrom to gain control of the speed. 
  * The score will be judged by how far you can descend before you die from either damage and how fast you can descend and how many mosnters you can kill. 
  * The player will have **one life**, but lots of health and you can gain health by killing monsters and falling through halos. 
  * The game will be played withing a QFrame.  There will be a score counter that will increase consistently the further the Doodle falls.  There will be three buttons at the top of screen that will be "start" "pause" and "quit". Since there is only one life, there is no need to display the lives.

##Controls 
* Click with your mouse to control your player, The DUDE! If you click near him on screen his movement will be finer and smaller. If you click your mouse nearer the bottom of the screen, the DUDE's movement will be greater. 
* Launch fireballs with the spacebar.  Activate fireball tracking after you shoot the fireball with the "g" key. 
* Press start, pause, and quit buttons to control gameplay.  If you quit before the game is over, your score will not be written to the file.

![Imgur](http://i.imgur.com/HZg6Mkr.jpg "Doodle Fall")

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

