#!/bin/bash
unzip -o ./libs/asio.zip -d ./libs
cmake CMakeLists.txt -DCMAKE_BUILD_TYPE=Release
make

cd client
cmake CMakeLists.txt -DCMAKE_BUILD_TYPE=Release
make
cd ..

#APP=$(pwd | grep -o '[^/]*$')
APP='linux-tool'

echo "$APP"
ZIP="$APP".zip
rm ./target -rf
mkdir -p target
cp ./bin/rpsa_client ./target
cd target
zip -r "$ZIP" *
mv  "$ZIP" ../"$ZIP"
cd ..
rm target -rf

