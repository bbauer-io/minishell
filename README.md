# meh$h>

A Unix command interpreter. It does everything you would want from a command interpreter, so long as you don't want pipes, redirections, auto-completion, or command history. (That's all coming up in version 2: a fully immersive shell simulator harnessing the full power of termcaps that's so real you'll forget you've left the comfort of zsh!).

WELL, THEN! What *does* it do?

It does quite a lot actually! Well beyond just lunching programs with execve()!.
* Has full featured builtin functions **cd, echo, env, setenv, unsetenv, exit, clear**.
* It keeps track of the environment.
* Manages the path, oldpwd, shlvl environment variables.
* Handles errors gracefully.
* Handles Ctrl+C to give back a fresh prompt after you've typed a bunch of stuff that you want to discard.
* Handles multiple command execution when separated with ';'.


That actually doesn't sound like that much...

Well, You'll have a pretty difficult time getting it to crash, if that's what you're trying to do. Go ahead and try it out!

How to use:
```
git clone https://github.com/brianbauer42/mehShell.git
cd mehShell
make
./minishell
???
profit!
```
**Despite the name, I'm proud of my stalwart *meh*$hell and looking forward to improving it.**

**100% leak free guaranteed!**
