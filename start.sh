./ircbot/ircbot &
tail -3 -f a.log | sed "s/å/aa/g" | sed "s/æ/ae/g" | sed "s/ø/oe/g" | ./irc /dev/ttyACM0
