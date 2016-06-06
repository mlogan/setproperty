# To reproduce:

	nvm install v6.2.1
	nvm use v6.2.1

	which npm # verify that this is from the v6.2.1 directory
	npm install -g node-gyp
	which node-gyp # verify that this is from the v6.2.1 directory
	node-gyp configure build

	which node # verify that this is from the v6.2.1 directory
	node test.js
