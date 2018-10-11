open BsReactNative;
open Paper;

module Styles = {
  open Style;

  let view = style([flexDirection(Row), alignItems(Center)]);

  let scrollArea =
    style([maxHeight(Pt(220.)), paddingHorizontal(Pt(0.))]);
  let contentContainerStyle = style([paddingHorizontal(Pt(24.))]);
};

let component = ReasonReact.statelessComponent("DialogWithLongText");

let make = (~close, ~visible, _children) => {
  ...component,
  render: _self =>
    <Portal>
      <Dialog onDismiss=close visible>
        <Dialog.Title> {ReasonReact.string("Alert")} </Dialog.Title>
        <Dialog.ScrollArea style=Styles.scrollArea>
          <ScrollView contentContainerStyle=Styles.contentContainerStyle>
            <Paragraph>
              {
                ReasonReact.string(
                  "Material is the metaphor\n\nA material metaphor is the unifying theory of a rationalized space and a system of motion. The material is grounded in tactile reality, inspired by the study of paper and ink, yet technologically advanced and open to imagination and magic.\n\n Surfaces and edges of the material provide visual cues that are grounded in reality. The use of familiar tactile attributes helps users quickly understand affordances. Yet the flexibility of the material creates new affordances that supersede those in the physical world, without breaking the rules of physics.\n\nThe fundamentals of light, surface, and movement are key to conveying how objects move, interact, and exist in space and in relation to each other. Realistic lighting shows seams, divides space, and indicates moving parts.",
                )
              }
            </Paragraph>
          </ScrollView>
        </Dialog.ScrollArea>
        <Dialog.Actions>
          <Button onPress={_event => close()}>
            {ReasonReact.string("OK")}
          </Button>
        </Dialog.Actions>
      </Dialog>
    </Portal>,
};
