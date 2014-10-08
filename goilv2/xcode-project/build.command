#!/bin/sh
cd `dirname $0` && xcodebuild -alltargets -configuration Default
