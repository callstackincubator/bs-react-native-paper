const path = require('path')
const glob = require('glob-to-regexp')
const blacklist = require('metro/src/blacklist')

const config = {
  getProjectRoots() {
    return [path.resolve(__dirname, '..'), __dirname]
  },

  getProvidesModuleNodeModules() {
    return ['react-native', 'reason-react', 'react-native-paper', 'bs-platform', 'bs-react-native']
  },

  getBlacklistRE() {
    return blacklist([glob(`${path.resolve(__dirname, '..')}/node_modules/*`)])
  },
}

module.exports = config
