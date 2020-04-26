![](images/mineriumcoin.png)


Minerium staging tree 
=========================

`master:` [![Build Status](https://travis-ci.org/minerium/minerium.svg?branch=master)](https://travis-ci.org/minerium/minerium) 

https://MineriumCoin.com


What is Minerium?
----------------

Minerium is a mineable SHA256 crypto currency, a coin which use the bitcoin protocol and blockchain technology.

Here are it's details and specifications:


• ASICS friendly

• 51% attacks resistant

• Adopts Segwit transations

• Based peer-to-peer cryptocurrency that is forked from Syscoin and Martkist coin

• Uses the POW (Proof of Work) combined with the Masternodes for more security and passive profits
 
 -Avoiding frozen blockchain - Blocks are fluid

• Adopts the technique of PrivateSend which allows anonymous transactions
 
 -It mixes all the transactions into multiple parts, everything inside one single transaction.


• The superblocks have been removed, and instead we implemented a new function called "SuperDay" during which the blocks reward receive an important augmentation of it's amount.
    The goal beeing to give a chance of the new miners joining the project late in time since it started, to mine it themselves,        and not being forced to buy at the exchange.
    Making a mining process less boring, less linear and more interesting.

![](images/block_rewards.png)

 
• Algorithm:        Sha256

• Block:            1 minute

• Difficulty:       3 blocks

• Ticker:           MINR

• Block size:       6mb

• P2P Port:         6116

• RPC Port:         6117

• Prune height:     1,000,000

• Max supply:       36,000,660 coins

• Masternodes:         15,000 coins

• POW Confirmations:   36

• Instant send Confirmations: 6

• Masternode Confirmations:   13

• Premined: 3 million (8.33%)  - for presale - first 200 masternodes  - Tip bots &  giveaway to community - bounties

•                 : Gains will be used for paying servers  such as explorers & website, the developers, 
		    future development for real use of the cryptocurrency in real life - 
		    new exchanges - aiming Binance (see Roadmap)

• Masternode cost at Pre-sale:   0.0225 BTC 1-4 first days 
                                    0.0300 BTC 5-7 last days




LINKS:

• Website: https://mineriumcoin.com

• Explorer: https://mineriumexplorer.com

• Twitter: https://twitter.com/mineriumcoin

• Discord: https://discord.gg/yPfMCwH

• Telegram: https://t.me/MineriumCoinOfficial




EXCHANGES:

• Exchange: https://erex.io






For more information, as well as an immediately useable, binary version of
the Minerium client sofware, see https://mineriumcoin.com/  (downloads section)



--------------------------------------------------------------------------------------



# Minerium-Masternode-Setup-Guide
 
<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Logo.png">




## Introduction

This guide is for a single masternode, on a Ubuntu 16.04 64-bit server (VPS) and Ubuntu 18.04 64-bit server (VPS) running headless and will be controlled from the wallet on your local computer (Control wallet). The wallet on the the VPS will be referred to as the Remote wallet.

You will need your masternode server details for progressing through this guide including the public IP address.

### VPS Server Recommendations ###

[Digital Ocean](https://www.digitalocean.com/products/droplets/)

[Vultr](https://www.vultr.com/products/cloud-compute/#compute)

**For either of the above VPS services, the economical $5 plan will be sufficient for your masternode.**

---

First the basic requirements:

1. 15,000 MINR
1. A main computer (your everyday computer) – This will run the MINERIUM Core wallet, hold your collateral 15,000 MINR and can be opened and closed without affecting the masternode.
1. Masternode Server (VPS Suggested – The wallet daemon that will be on 24/7).
1. A unique IP address for your VPS / Remote wallet.

**For security reasons, you’re are going to need a different IP for each masternode you plan to host.**


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Available-balance.png">

## Configuration

**Step 1:** Using the control wallet, enter the debug console `Tools > Debug console` and type the following command:

<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Debug-console.png">

```
masternode genkey
```
<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/masternode-genkey.png">

*(This will be the masternode’s privkey variable. We will need this later…)*



**Step 2:** Using the control wallet, enter the following command:

```
getnewaddress masternode01
```

<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/getnewaddress01.png">


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/getnewaddress.png">


**Step 3:** Still in the control wallet, send 15,000 MINR to the wallet address you generated in Step 2. 

Be 100% sure that you entered the address correctly. You can verify this when you paste the address into the **"Pay To:"** field, the label will auto populate with the name you chose. 

Also make sure this is exactly **15,000 MINR**; No less, no more.

**Be absolutely sure the send to address is copied correctly and then check it again. We cannot help you if you send 15,000 MINR to an incorrect address.**


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Collateral-send.png">


Please allow at least 1 block confirmation to complete before moving on.

**Step 4:** Still in the control wallet, enter the command into the console:

```
masternode outputs
```

<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/masternode_outputs.png">


*This gets the proof of transaction of sending 15,000 MINR*

**Step 5:** Still on the main computer, go into the MINR data directory:

OS | Path to MINERIUM
------------ | -------------
Windows | `%Appdata%/Roaming/Minerium/`
macOS | `~/Library/Application\ Support/Minerium/`
Linux | `~/.mineriumcore/`

Find the masternode.conf file, edit it in your favorite text editor and add the following line to it:

```
<Name of Masternode(Use the name you entered earlier for simplicity)> <Unique VPS Public IP address>:42122 <The result of Step 1> <Result of Step 4> <The number after the long line in Step 4>
```

Example:

```
masternode01 127.0.0.2:6116 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
```

Substitute with your own values without the "<>"s.


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/masternode.conf.png">


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/masternode.conf3.png">




Lastly, close the control wallet and open again to load the new configuration file.

## VPS Remote Wallet Install

Install the latest version of the Minerium Core wallet onto your masternode. The latest version can be found here: [Minerium Core Releases](https://github.com/MINERIUM-COIN/minerium/releases).

**Step 1:** Log in to your VPS via SSH:

```
cd ~
```

**Step 2:** From your home directory, download the latest version from the Minerium GitHub repository:

For Linux 16.04:
```
wget https://github.com/MINERIUM-COIN/minerium/releases/download/v3.0.0/Linux16.04-64bits.zip
```
For Linux Obuntu 18.04:
```
wget https://github.com/MINERIUM-COIN/minerium/releases/download/v3.0.0/Linux18.04-64bits.zip
```

Always check the releases page for the latest version and update the URL to reflect the most current version.

**Step 3:** Unzip & Extract:

For Linux Obuntu 16.04:

```
unzip Linux16.04-64bits.zip
```

For Linux Obuntu 18.04:
```
unzip Linux18.04-64bits.zip
```

**Step 4:** Copy the files to the local bin. **Requires sudo**

```
sudo cp mineriumd /usr/local/bin
sudo cp minerium-cli /usr/local/bin
```

**Step 5:** Note: If this is the first time running the wallet in the VPS, you’ll need to attempt to start the wallet:

```
mineriumd --daemon
```

**Step 6:** Stop the daemon after the blockchain downloads:

You can verify you have the entire blockchain by comparing the results of `minerium-cli getinfo` with the [Minerium Block Explorer](https://mineriumexplorer.com/)

Once verified:

```
minerium-cli stop
```

**Step 7:** Navigate to the mineriumcore data directory:

```
cd ~/.mineriumcore
```

**Step 8:** Open the configuration file by typing:

```
nano minerium.conf
```

**Step 9:** Make the config look like this with your values:

```
rpcuser=long_random_username
rpcpassword=longer_random_password
rpcallowip=127.0.0.1
server=1
daemon=1
logtimestamps=1
maxconnections=256
masternode=1
bind=Your VPS unique public ip address
port=6116
externalip=Your VPS unique public ip address
masternodeaddr=Your VPS unique public ip:6116
masternodeprivkey=Result of Step 1
```

*Make sure to replace rpcuser and rpcpassword with your own.*



<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Remote_minerium.conf.png">


**Step 10:** Save and exit the file:

```
Ctr+x to exit and press Y to save changes and press enter to close
```

**Please be sure to have port 6116 open on your server firewall if applicable for your control wallet to be able start the masternode remotely.**

## Start the Masternode

**Step 1:** Navigate back to the Minerium core VPS server:


**Step 2:** Start the wallet daemon:

```
mineriumd --daemon
```


**Make sure your wallet synchronizing complete before start masternode:**


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Sync-data.png">


<img src="https://github.com/captain-8421/Minerium-Masternode-Setup-Guide/blob/guide-image/Sync.png">


**Step 3:** From the Control wallet debug console:

```
masternode start-alias masternode01
```

Where "masternode01" is the name of your masternode alias we shown in example,you can choose yours.


**The following should appear.**

```
{
  "overall": "Successfully started 1 masternodes, failed to start 0, total 1",
  "detail": [
    {
      "alias": "MN1",
      "result": "successful",
      "error": ""
    }
  ]
}

```

Or start yous masternode using **Initialize masternode** From the Masternode Tab

<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/start_masternode0.png">


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Start-masternode.png">


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/Successfully_started.png">


**Step 4:** Use the following command to check status:

```
minerium-cli masternode status
```

You should see something like:

```
{
  "txhash": "2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c",
  "outputidx": 0,
  "netaddr": "127.0.0.1:6116",
  "addr": "MGEonPLWN1YAxZnpPj4iTsiWzZxPbSN9XP",
  "status": 4,
  "message": "Masternode successfully started"
}
```
Before **ENABLED** STATUS, your masternode will remain in **PRE_ENABLED** status for some minutes.


<img src="https://raw.githubusercontent.com/captain-8421/Minerium-Masternode-Setup-Guide/guide-image/PRE_ENABLED.png">




If you see status Not capable masternode: Hot node, waiting for remote activation, you need to wait a bit longer for the blockchain to reach consensus. It's possible it may take 60 to 120 minutes before the activation can be done. You can also try restarting the VPS wallet `minerium-cli stop` and then `mineriumd --daemon` and trying the `masternode start-alias masternode01` command again local wallet.

Minerium core Masternode Setup is Complete!




## Tearing down a Masternode

1. `minerium-cli stop` from the masternode to stop the wallet.
1. Then from your control wallet, edit your masternode.conf, delete the **masternode01** line entry.
1. Restart the control wallet.
1. Your 15,000 MINR will now be unlocked.



License
-------

MineriumCoin is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is meant to be stable. Development is normally done in separate branches.
[Tags](https://github.com/minerium/minerium/tags) are created to indicate new official,
stable release versions of Minerium Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code.

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/qa) are installed) with: `qa/pull-tester/rpc-tests.py`

Minerium test suites can run by `cd src/test && ./test_minerium`

The Travis CI system makes sure that every pull request is built for Windows
and Linux, OS X, and that unit and sanity tests are automatically run.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

Translations
------------

Changes to translations as well as new translations can be submitted to
[Minerium Core's Transifex page](https://www.transifex.com/projects/p/minerium/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

