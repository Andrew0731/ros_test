
"use strict";

let GetNumOfWaypoints = require('./GetNumOfWaypoints.js')
let SaveWaypoints = require('./SaveWaypoints.js')
let GetWaypointByName = require('./GetWaypointByName.js')
let AddNewWaypoint = require('./AddNewWaypoint.js')
let GetWaypointByIndex = require('./GetWaypointByIndex.js')
let GetChargerByName = require('./GetChargerByName.js')

module.exports = {
  GetNumOfWaypoints: GetNumOfWaypoints,
  SaveWaypoints: SaveWaypoints,
  GetWaypointByName: GetWaypointByName,
  AddNewWaypoint: AddNewWaypoint,
  GetWaypointByIndex: GetWaypointByIndex,
  GetChargerByName: GetChargerByName,
};
