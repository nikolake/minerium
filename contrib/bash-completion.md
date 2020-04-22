Bash Completion
---------------------

The following script provide bash completion functionality for `sycoind` and `minerium-cli`.

* `contrib/mineriumd.bash-completion`
* `contrib/minerium-cli.bash-completion`
* `contrib/_osx.bash-completion`

### OSX ###
Use `brew` to install `bash-completion` then update `~/.bashrc` to include the completion scripts and helper functions to provide `have()` and `_have()` on OSX.

The example assumes Minerium was compiled in `~/minerium` and the scripts will be availabe in `~/minerium/contrib`, however they can be moved to a different location.

```
brew install bash bash-completion
sudo bash -c 'echo /usr/local/bin/bash >> /etc/shells'
chsh -s /usr/local/bin/bash

BASHRC=$(cat <<EOF
if [ -f $(brew --prefix)/etc/bash_completion ]; then
  . $(brew --prefix)/etc/bash_completion
fi
. ~/minerium/contrib/_osx.bash-completion
. ~/minerium/contrib/mineriumd.bash-completion
. ~/minerium/contrib/minerium-cli.bash-completion
EOF
)

grep -q "/etc/bash_completion" ~/.bashrc || echo "$BASHRC" >> ~/.bashrc
. ~/.bashrc

```