'use strict';
// #eae4c2
window.onload = () => {
  const grid = document.getElementById('grid');
  const ctrlPanel = document.getElementById('ctrl-panel');
  const load = document.querySelector('form');
  const zoom = document.getElementById('pixel');
  const colorPicker = document.getElementById('color');
  const fillButton = document.getElementById('fill');
  const gridToggle = document.getElementById('toggle');
  const eraseButton = document.getElementById('erase');
  const state = {
    resolution: {w: 15, h: 10},
    pixel: 70,
    mouseDown: false,
    grid: true,
    color: '#1DA1F2',
    fillColor: '#EAE1D0'
  };

  renderCanvas(grid, state.resolution, state.pixel, function(ev) {
    if (state.mouseDown || ev.type == 'click')
      ev.target.style.backgroundColor = state.color;
  });

// -----
  grid.addEventListener('mousedown', function(ev) {
    state.mouseDown = true;
    ctrlPanel.style.pointerEvents = 'none';
  });
  document.addEventListener('mouseup', function(ev) {
    state.mouseDown = false;
    ctrlPanel.style.pointerEvents = 'auto';
  });

  zoom.addEventListener('input', function(ev) {
    state.pixel = ev.target.value;
    grid.style.width = `${state.resolution.w * state.pixel}px`;
    grid.style.height = `${state.resolution.h * state.pixel}px`;
    styleChildren(grid, {width: `${state.pixel}px`, height: `${state.pixel}px`});
  });

  colorPicker.addEventListener('input', function(ev) {
    state.color = ev.target.value;
  });

  gridToggle.addEventListener('click', function(ev) {
    if (state.grid) {
      styleChildren(grid, {borderStyle: 'none'});
      state.grid = false;
    } else {
      styleChildren(grid, {borderStyle: 'solid'});
      state.grid = true;
    }
  });

  fillButton.addEventListener('click', function(ev) {
    state.fillColor = state.color;
    this.style.color = state.color;
    styleChildren(grid, {backgroundColor: state.color});
  });

};
