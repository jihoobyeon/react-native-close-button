const RNCloseButton = require('./NativeRNCloseButton').default;

export function doBeforeClose(toDo: () => void): void {
  return RNCloseButton.doBeforeClose(toDo);
}

export function closeNow(): void {
  return RNCloseButton.closeNow();
}