
"use strict";

let SetComplianceSlope = require('./SetComplianceSlope.js')
let StopController = require('./StopController.js')
let RestartController = require('./RestartController.js')
let TorqueEnable = require('./TorqueEnable.js')
let StartController = require('./StartController.js')
let SetComplianceMargin = require('./SetComplianceMargin.js')
let SetCompliancePunch = require('./SetCompliancePunch.js')
let SetSpeed = require('./SetSpeed.js')
let SetTorqueLimit = require('./SetTorqueLimit.js')

module.exports = {
  SetComplianceSlope: SetComplianceSlope,
  StopController: StopController,
  RestartController: RestartController,
  TorqueEnable: TorqueEnable,
  StartController: StartController,
  SetComplianceMargin: SetComplianceMargin,
  SetCompliancePunch: SetCompliancePunch,
  SetSpeed: SetSpeed,
  SetTorqueLimit: SetTorqueLimit,
};
