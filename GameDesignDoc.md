# Doodle Dive

My game is inspired by the game Doodle Jump by made by Lima Sky.  Doodle jump is a game where yor character continues to jump up platforms, and the higher the character jumps, the more points accumulate.  In this ascent, you have to find platorms to land on.  In addition, you have to avoid mosters and black warp holes that will end the game.  The gameplay  utlizes the gyroscope startphones, so direction of the doodle character jump is controlled by the angle in which the user holds the phone.  

Doodle Dive is the reverse narrative.  In Doodle Dive, the Doodle character will be falling!  The Doodle character will fall through the sky.  There will be platorms to bounce of and monsters to avoid!  

![alt text] (http://a221.phobos.apple.com/us/r1000/061/Purple2/v4/cc/af/a0/ccafa0fb-d14e-38db-cab4-4ed254f8a0eb/mzl.mdotkunf.320x480-75.jpg "Doodle Jump by Lima Sky")

# Implementation
## Things In the Game 
  1. Platforms: Platforms to bounce off up will consistently be moving upwards to make it appear as if the Doodle character is falling.  These platforms will be ***safe to land on** and stationary (but technically moving upwards).  Depending on what I decide, either my character will stop on said platform or my character will automatically bounce up from the platform (similar to the doodle jump game). These will probably be blue.  
  2. Super Platforms: This are good platforms that you are allowed to touch but they will be moving from side to side, going from one side of the screen to the other.  These super platforms will probably dissapear off the platform as they move out of view.  They will be a different color than the regular platorms and they will be slightly smaller. 
  3. Angry Platforms: This platorms are bad.  They will kill you because they have spikes on them and this will give you damage.  Similar to the regular platforms they will move upwards to make the illusion of the Doodle character moving downwards.  They will be smaller than regular platorms but they will also oscilate a little bit. They will have **spikes** on them.
  4. Air Rings: If you fall through these rings, you will get bonus points.  These rings are an homage to the sky rings that can be found in _Super Mario 64_.  This rings will be moving side to side and will come in different colors. 
  5. Monsters: If you crash into a monster, you die. **Game over**. (Game can also be over if you get enough damage from the Angry Platforms) These monster will look like monsters. 

## Game Play
  * The fall will be controlled by mouse clicks.  When you click and hold down the mouse the Doodle will fall in that direction.  The Doodle will pick up speed toward the click location as long as the click is held down.  The momentum of this fall will continue after the click and will eventually decay.  This will create a sort of _floaty_ fall that will make it fun to control.
  * The socre will be judged by how far you can descend before you die from either damage or a monster.  So each level will have a set score that you can get if you reach the bottom.  But there is an opportunity to get even more points if you get _bounus points_ as you fall through the Air Rings. 
  * The player will have **one life**. 
  * The game will be plays a scene and a view of that scene.  There will be a score counter that will increase consistently the further the Doodle falls.  There will be three buttons at the top of screen that will be "start" "pause" and "quit". Since there is only one life, there is no need to display the lives.  When the Doodle dies, there will be a pop-up screen to show what the score is.  At this point, the user will have the opportunity to enter their name if they have a new high score. 



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

