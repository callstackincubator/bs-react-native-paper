type jsIconProps = {
  .
  "color": string,
  "size": float,
};

type iconProps = {
  color: string,
  size: float,
};

type renderIcon = jsIconProps => ReasonReact.reactElement;

let renderIcon =
    (reRenderIcon: iconProps => ReasonReact.reactElement): renderIcon =>
  (jsIconProps: jsIconProps) =>
    reRenderIcon({color: jsIconProps##color, size: jsIconProps##size});

type iconType =
  | Name(string)
  | Element(renderIcon);
