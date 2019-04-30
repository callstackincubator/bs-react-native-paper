type jsIconProps = {
  .
  "color": string,
  "size": float,
  "direction": string,
};

type iconProps = {
  color: string,
  size: float,
  direction: string,
};

type renderIcon = jsIconProps => React.element;

let renderIcon = (reRenderIcon: iconProps => React.element): renderIcon =>
  (jsIconProps: jsIconProps) =>
    reRenderIcon({
      color: jsIconProps##color,
      size: jsIconProps##size,
      direction: jsIconProps##direction,
    });

type iconType =
  | Name(string)
  | Element(renderIcon);
