Source: https://github.com/sadekbaroudi/qmk_firmware/blob/master/keyboards/fingerpunch/FIRMWARE.md

# Building firmware

There are a couple of methods to build firmware. The traditional method and the fingerpunch build script.

To build your own firmware, the recommendation is to use the fingerpunch firmware builder, since it accounts for all the possible fingerpunch features.

## fingerpunch build script

 The script is available in the git repo:  
 [/bin/fp_build.sh](/bin/fp_build.sh)

 In other words, you run it from the qmk root directory as follows:  
 ```
 $ bin/fp_build.sh -h

 Usage: bin/fp_build.sh -k <keyboard> -m <keymap> -c <convert_to controller> -r -h

  -l list valid keyboards (optional, overrides all other options)
  -k keyboard directory (optional, default is all fingerpunch keyboards)
  -m keymap (optional, defaults to the 'default' keymap)
  -c add CONVERT_TO parameter for a controller (eg -c stemcell)
  -i (interactive mode, take feature selection user input to generate build command)
  -r (run the build command(s), defaults to outputting the build string)
  -h (show this dialog)
 ```

The interactive mode will help you configure based on your keyboard setup. For example:

```
$ bin/fp_build.sh -k ffkb_byomcu/v3 -m default -i -c stemcell -r
Running for keyboards/fingerpunch/ffkb_byomcu/v3
make fingerpunch/ffkb_byomcu/v3:default
Do you have a cirque? (yes/no): n
Do you have a trackball? (yes/no): y
No RGB, RGB light, RGB matrix? (0-2): 2
No rotary encoders, EC11, or EVQ? (0-2): 1

make fingerpunch/ffkb_byomcu/v3:default CIRQUE_ENABLE=no FP_TRACKBALL_ENABLE=yes RGB_MATRIX_ENABLE=yes FP_EC11=yes CONVERT_TO=stemcell
fp_build.sh: Running QMK Build....
```


# Branch Maintenance

Add the fingerpunch repo as a remote repository
`git remote add fingerpunch git@github.com:sadekbaroudi/qmk_firmware.git`
`git fetch fingerpunch`

Checkout the master branch as a branch that tracks your keyboard. Let's use ffkb in this example
`git checkout -b ffkb fingerpunch/master`
`git submodule update`

add your keymap, code, etc into keyboards/fingerpunch/ffkb_byomcu/v3/keymaps/{your_keymap_dir}

commit your changes
`git commit -a -m "Your commit message"`

push the branch to your repo
`git push origin ffkb`

If you ever want to update from the latest fingerpunch master branch in the future
`git fetch fingerpunch`
`git merge fingerpunch/master`
`git push origin ffkb`
