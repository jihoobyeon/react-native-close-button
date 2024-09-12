const CloseButton = require('./NativeCloseButton').default;

export function doBeforeClose(toDo: () => void): void {
  return CloseButton.doBeforeClose(toDo);
}

export function closeNow(): void {
  return CloseButton.closeNow();
}