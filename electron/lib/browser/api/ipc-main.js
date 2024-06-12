const EventEmitter = require('events').EventEmitter;
var ipcMain = new EventEmitter();
ipcMain.handle = function (channel, listener) {
    ipcMain.on(channel, function (event, ...args) {
        var promise = listener(channel, event, ...args);
        if (promise.toString() != "[object Promise]")
            return;
        promise.then(function(result) {
            event.sender.send('ipc-main-handle-reply', result);
        });
    });
}

module.exports = ipcMain;

// Do not throw exception when channel name is "error".
module.exports.on('error', () => {})
