[@bs.module "react-native-paper"]
external listAccordion: ReasonReact.reactClass = "ListAccordion";

[@bs.deriving abstract]
type props = {
  title: string,
  [@bs.optional]
  description: string,
  [@bs.optional]
  icon: Paper_Icon.props => ReasonReact.reactElement,
  [@bs.optional]
  theme: Paper_ThemeProvider.appTheme,
  [@bs.optional]
  style: BsReactNative.Style.t,
};

let make = (~title, ~description=?, ~icon=?, ~theme=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=listAccordion,
    ~props=props(~title, ~description?, ~icon?, ~theme?, ()),
    children,
  );
